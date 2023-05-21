#include "functions.h"
#include "customVector.h"
#include <string>
// #include "customVector"

using namespace std;

void duomenysIvedamiKonsoleje(customVector<studentas>& visiStudentai, string studSkaicius);

int main() {
    string studSkaicius;
    string dataFaileArIvesti;
    customVector<studentas> visiStudentai;

    cout << "Ar norite duomenis nuskaityti is failo? Mygtukas 'f' - duomenys vedami konsoleje. Bet kas kitas - failo pavadinimas(.txt gale nebereikia - bus automatiskai prideta)" << endl;
    cin >> dataFaileArIvesti; // arba "f", arba failo pavadinimas
    if(dataFaileArIvesti != "f"){
        duomenysIsFailo(visiStudentai, dataFaileArIvesti);
        if(visiStudentai.size() == 0)return 0;
        studSkaicius = to_string(visiStudentai.size());

    } else {
        studentuSkIvedimas:
        cout << "Studentu skaicius: ";
        cin >> studSkaicius;
        if(!isNumber(studSkaicius)){
            cout << "Studentu skaicius turi buti sveikasis skaicius. Iveskite is naujo." << endl; 
            goto studentuSkIvedimas;
        }

        duomenysIvedamiKonsoleje(visiStudentai, studSkaicius);
    }

    // rusiavimas pagal varde/pavarde
    mergesort<customVector<studentas>>(visiStudentai, 0, visiStudentai.size() - 1);

    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis(vid.)" << setw(20) << "Galutinis(med.)" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    try{
        for(int i = 0; i < stoi(studSkaicius); i++){
            cout << setw(15) << visiStudentai[i].getVardas();
            cout << setw(15) << visiStudentai[i].getPavarde();
            cout << setw(20) << fixed << setprecision(2) << visiStudentai[i].getGalutinisBalas(); // Galutinis(vid.)
            if(stoi(visiStudentai[i].getNdKiekis()) % 2 == 0){ // Galutinis(med.)
                cout << setw(20) << fixed << setprecision(2) << (double)(stoi(visiStudentai[i].getNdRez().at(stoi(visiStudentai[i].getNdKiekis())/2)) + stoi(visiStudentai[i].getNdRez().at(stoi(visiStudentai[i].getNdKiekis())/2 - 1)))/2 * 0.4 + (stoi(visiStudentai[i].getEgzaminoRez()) * 0.6);
            } else {
                cout << setw(20) << fixed << setprecision(2) <<  (stoi(visiStudentai[i].getNdRez().at(stoi(visiStudentai[i].getNdKiekis())/2)) * 0.4) + (stoi(visiStudentai[i].getEgzaminoRez()) * 0.6);
            }
            cout << endl;
        }
    } catch (...) {
        cout << "Klaida isvedant duomenis." << endl;
    }

    return 0;
}

void duomenysIvedamiKonsoleje(customVector<studentas>& visiStudentai, string studSkaicius){

    srand(time(0));

    for (int i = 0; i < stoi(studSkaicius); i++){
        string atsitiktiniaiRez;
        studentas studentas;
        cout << "iveskite " << i + 1 << " studento informacija:" << endl;
        string v;
        cout << "Vardas: ";
        cin >> v;
        studentas.setVardas(v);
        string p;
        cout << "Pavarde: ";
        cin >> p;
        studentas.setPavarde(p);

        egzaminoRezIvedimas:
        string er;
        cout << "Egzamino rezultatas: ";
        cin >> er;
        studentas.setEgzaminoRez(er);
        if(!isNumber(studentas.getEgzaminoRez())){
            cout << "Egzamino rezultatas turi buti sveikasis skaicius. Iveskite is naujo." << endl; 
            goto egzaminoRezIvedimas;
        }
        if(stoi(studentas.getEgzaminoRez()) > 10 || stoi(studentas.getEgzaminoRez()) < 1){
            cout << "Egzamino rezultatas turi buti tarp 1 ir 10. Iveskite is naujo." << endl;
            goto egzaminoRezIvedimas;
        }

        cout << "Ar generuoti namu darbu rezultatus atsitiktinai? 't' jei taip, bet koks kitas simbolis jei ne: ";
        cin >> atsitiktiniaiRez;

        NDIvedimas:
        string ndk;
        cout << "Namu darbu kiekis: ";
        cin >> ndk;
        studentas.setNdKiekis(ndk);
        if(!isNumber(studentas.getNdKiekis())){
            cout << "Namu darbu kiekis turi buti sveikasis skaicius. Iveskite is naujo." << endl; 
            goto NDIvedimas;
        } else if(stoi(studentas.getNdKiekis()) <= 0){
            cout << "Namu darbu kiekis turi buti daugiau uz nuli. Iveskite is naujo." << endl;
            goto NDIvedimas;
        }
        
        
        int bendrasNDbalas = 0;

        if(atsitiktiniaiRez == "t"){
            customVector<string> ndRez;
            for (int j = 0; j < stoi(studentas.getNdKiekis()); j++) {
                auto x = studentas.getNdRez();
                x.push_back(to_string(rand() % 10 + 1));
                studentas.setNdRez(x);
                bendrasNDbalas = stoi(studentas.getNdRez().at(j)) + bendrasNDbalas;
            }
        } else{
            customVector<string> ndRez;

            for (int j = 0; j < stoi(studentas.getNdKiekis()); j++) {
                uzdRezIvedimas:
                cout << "Rezultatas uzduoties " << j + 1 << ": ";
                string val;
                cin >> val;
                auto x = studentas.getNdRez();
                x.push_back(val);
                studentas.setNdRez(x);

                if(!isNumber(studentas.getNdRez().at(j))){
                    cout << "Uzduoties rezultatas turi buti sveikasis skaicius. Iveskite is naujo." << endl;
                    goto uzdRezIvedimas;
                } else {
                    bendrasNDbalas = bendrasNDbalas + stoi(studentas.getNdRez().at(j));
                }
            }
        }
        studentas.skaiciuotiGalutiniBala();
        //  = ((double)bendrasNDbalas/stoi(studentas.getNdKiekis())) * 0.4 + (stoi(studentas.getEgzaminoRez()) * 0.6);

        visiStudentai.push_back(studentas);
    }
}