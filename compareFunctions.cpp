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

void sortStudentsLIST(list<studentasList> visiStudentai, list<studentasList>& blogi, list<studentasList>& geri){
    list<studentasList>::iterator it = visiStudentai.begin();
  
    for (std::list<studentasList>::iterator it = visiStudentai.begin(); it != visiStudentai.end(); ++it){
        if(it->getGalutinisBalas() < 5){
        blogi.push_back(*it);
    } else {
        geri.push_back(*it);
    }
    }
}

void sortStudentsDEQUE(deque<studentasDeque> visiStudentai, deque<studentasDeque>& blogi, deque<studentasDeque>& geri){ // "studentai1000" - be .txt
    for(int i = 0; i < visiStudentai.size(); i++){
        if(visiStudentai.at(i).getGalutinisBalas() < 5){
            blogi.push_back(visiStudentai.at(i));
        } else {
            geri.push_back(visiStudentai.at(i));
        }
    }
}