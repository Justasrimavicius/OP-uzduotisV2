
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include "iomanip"
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cmath>
#include <vector>
#include <string>
#include <random>

using namespace std;

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::string egzaminoRez;
    std::vector<std::string> ndRez;
    std::string ndKiekis;
    double galutinisBalas;
};

bool isNumber(const std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void merge(std::vector<studentas>& arr, int l, int m, int r) {
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
        string eilute;

        getline(failas, eilute);
        istringstream iss(eilute);
        vector<string> headers;
        string header;
        while (iss >> header) {
            headers.push_back(header);
        }

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
       outfile << left << setw(15) << ((double)bendrasNDbalas/stoi(ndKiekis)) * 0.4 + (dis(gen) * 0.6);
        outfile << endl;
    }
    outfile.close();
    return 0;
}

int sortStudents(string fileName, vector<studentas> visiStudentai){ // "studentai1000" - be .txt
    ofstream outfileBlogi (fileName + "blogi.txt");
    ofstream outfileProtingi (fileName + "protingi.txt");

    outfileBlogi << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";
    outfileProtingi << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";

    for(int i = 1; i <= stoi(visiStudentai.at(0).ndKiekis); i++){
        outfileBlogi << left << setw(10) << "ND" + to_string(i);
        outfileProtingi << left << setw(10) << "ND" + to_string(i);
    }

    outfileBlogi << left << setw(15) << "Egz." << endl;
    outfileProtingi << left << setw(15) << "Egz." << endl;


    int size = visiStudentai.size();
    for(int i = 0; i < size; i++){
        // cout << visiStudentai.at(i).vardas;
        if(visiStudentai.at(i).galutinisBalas < 5){
            outfileBlogi << left << setw(20) << visiStudentai.at(i).vardas << left << setw(20) << visiStudentai.at(i).pavarde;

            for(int j = 0; j < stoi(visiStudentai.at(i).ndKiekis); j++){
                outfileBlogi << left << setw(10) << fixed << setprecision(2) << visiStudentai.at(i).ndRez.at(j);
            }

            outfileBlogi << left << setw(15) << visiStudentai.at(i).egzaminoRez;
            outfileBlogi << endl;
        } else {
            outfileProtingi << left << setw(20) << visiStudentai.at(i).vardas << left << setw(20) << visiStudentai.at(i).pavarde;

            for(int j = 0; j < stoi(visiStudentai.at(i).ndKiekis); j++){
                outfileProtingi << left << setw(10) << fixed << setprecision(2) << visiStudentai.at(i).ndRez.at(j);
            }
            
            outfileProtingi << left << setw(15) << visiStudentai.at(i).egzaminoRez;
            outfileProtingi << endl;
        }
    }
    return 0;
}