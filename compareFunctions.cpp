#include "functions.h"
#include "compare.h"

void duomenysIsFailoLIST(list<studentasList>& visiStudentai, string fileName){
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
            studentasList studentas;
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

void duomenysIsFailoDEQUE(deque<studentasDeque>& visiStudentai, string fileName){
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
            studentasDeque studentas;
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

void sortStudentsLIST(list<studentasList> visiStudentai, list<studentasList>& blogi, list<studentasList>& geri){
    list<studentasList>::iterator it = visiStudentai.begin();
  
    for (std::list<studentasList>::iterator it = visiStudentai.begin(); it != visiStudentai.end(); ++it){
        if(it->galutinisBalas < 5){
        blogi.push_back(*it);
    } else {
        geri.push_back(*it);
    }
    }
}

void sortStudentsDEQUE(deque<studentasDeque> visiStudentai, deque<studentasDeque>& blogi, deque<studentasDeque>& geri){ // "studentai1000" - be .txt
    for(int i = 0; i < visiStudentai.size(); i++){
        if(visiStudentai.at(i).galutinisBalas < 5){
            blogi.push_back(visiStudentai.at(i));
        } else {
            geri.push_back(visiStudentai.at(i));
        }
    }
}