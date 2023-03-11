#include "functions.h"

bool isNumber(const std::string &s){
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void merge(std::vector<studentas>& arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    std::vector<studentas> L(n1), R(n2);
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i].vardas <= R[j].vardas){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergesort(std::vector<studentas>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void duomenysIsFailo(vector<studentas>& visiStudentai, string fileName){
    try{
        ifstream failas(fileName + ".txt");
        if(failas.fail())throw (false);
        string eilute;

        getline(failas, eilute);
        istringstream iss(eilute);
        vector<string> headers;
        string header;
        while (iss >> header) {
            headers.push_back(header);
        }
        if(headers.size() < 4)throw (false);
        while (getline(failas, eilute)){
            istringstream iss(eilute);
            studentas studentas;
            iss >> studentas.vardas >> studentas.pavarde;

            string nd;
            int bendrasNDbalas = 0;
            int ndQty = 0;
            for (int i = 0; i < headers.size() - 3; ++i) {
                iss >> nd;
                studentas.ndRez.push_back(nd);
                bendrasNDbalas += stoi(nd);
                nd = "";
                ndQty++;
            }

            iss >> studentas.egzaminoRez;
            studentas.ndKiekis = to_string(ndQty);
            studentas.galutinisBalas = ((double)bendrasNDbalas/stoi(studentas.ndKiekis)) * 0.4 + (stoi(studentas.egzaminoRez) * 0.6);

            visiStudentai.push_back(studentas);
        }
        failas.close();
    } catch (...) {
        cout << "Klaida ivedant duomenis is failo." << endl;
    }
}

int generateFile(string studKiekis, string ndKiekis){
    int bendrasNDbalas = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    ofstream outfile ("studentai"+studKiekis+".txt");

    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";

    for(int i = 1; i <= stoi(ndKiekis); i++){
        outfile << left << setw(10) << "ND" + to_string(i);
    }
    outfile << left << setw(15) << "Egz." << endl;

    for(int i = 1; i <= stoi(studKiekis); i++){
        outfile << left << setw(20) << "Vardas" + to_string(i) << left << setw(20) << "Pavarde" + to_string(i);
        int bendrasNDbalas = 0;
        for(int j = 1; j <= stoi(ndKiekis); j++){
            int nd = dis(gen);
            outfile << left << setw(10) << fixed << setprecision(2) << nd;
            bendrasNDbalas = bendrasNDbalas + nd;
        }
       outfile << left << setw(15) << dis(gen);
        outfile << endl;
    }
    outfile.close();
    return 0;
}

void sortStudents(vector<studentas> visiStudentai, vector<studentas>& blogi, vector<studentas>& geri){ // "studentai1000" - be .txt
    for(int i = 0; i < visiStudentai.size(); i++){
        if(visiStudentai.at(i).galutinisBalas < 5){
            blogi.push_back(visiStudentai.at(i));
        } else {
            geri.push_back(visiStudentai.at(i));
        }
    }
}

void outputFile(string fileName, vector<studentas>& vector){
    ofstream outfile(fileName + ".txt");

    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";

    for(int i = 1; i <= stoi(vector.at(0).ndKiekis); i++){
        outfile << left << setw(10) << "ND" + to_string(i);
    }

    outfile << left << setw(15) << "Egz." << endl;

    int size = vector.size();
    for(int i = 0; i < size; i++){
        outfile << left << setw(20) << vector.at(i).vardas << left << setw(20) << vector.at(i).pavarde;

        for(int j = 0; j < stoi(vector.at(i).ndKiekis); j++){
            outfile << left << setw(10) << fixed << setprecision(2) << vector.at(i).ndRez.at(j);
        }

        outfile << left << setw(15) << vector.at(i).egzaminoRez;
        outfile << endl;
    }
}
