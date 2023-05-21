#include "functions.h"
#include "customVector.h"
bool isNumber(const std::string &s){
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}


void duomenysIsFailo(customVector<studentas>& visiStudentai, string fileName){
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
            string v;
            string p;
            iss >> v >> p;
            studentas.setVardas(v);
            studentas.setPavarde(p);

            string nd;
            int bendrasNDbalas = 0;
            int ndQty = 0;
            for (int i = 0; i < headers.size() - 3; ++i) {
                iss >> nd;
                auto x = studentas.getNdRez();
                x.push_back(nd);
                studentas.setNdRez(x);
                bendrasNDbalas += stoi(nd);
                nd = "";
                ndQty++;
            }
            string er;
            iss >> er;
            studentas.setEgzaminoRez(er);
            studentas.setNdKiekis(to_string(ndQty));
            studentas.skaiciuotiGalutiniBala();
            //  = ((double)bendrasNDbalas/stoi(studentas.ndKiekis)) * 0.4 + (stoi(studentas.egzaminoRez) * 0.6);

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

void sortStudents(customVector<studentas> visiStudentai, customVector<studentas>& blogi, customVector<studentas>& geri){ // "studentai1000" - be .txt
    for(int i = 0; i < visiStudentai.size(); i++){
        if(visiStudentai.at(i).getGalutinisBalas() < 5){
            blogi.push_back(visiStudentai.at(i));
        } else {
            geri.push_back(visiStudentai.at(i));
        }
    }
}

void outputFile(string fileName, customVector<studentas>& vector){
    ofstream outfile(fileName + ".txt");

    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";

    for(int i = 1; i <= stoi(vector.at(0).getNdKiekis()); i++){
        outfile << left << setw(10) << "ND" + to_string(i);
    }

    outfile << left << setw(15) << "Egz." << endl;

    int size = vector.size();
    for(int i = 0; i < size; i++){
        outfile << left << setw(20) << vector.at(i).getVardas() << left << setw(20) << vector.at(i).getPavarde();

        for(int j = 0; j < stoi(vector.at(i).getNdKiekis()); j++){
            outfile << left << setw(10) << fixed << setprecision(2) << vector.at(i).getNdRez().at(j);
        }

        outfile << left << setw(15) << vector.at(i).getEgzaminoRez();
        outfile << endl;
    }
}
