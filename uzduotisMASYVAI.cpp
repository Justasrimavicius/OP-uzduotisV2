#include <cstdlib>
#include <ctime>
#include <time.h>
#include "functions.h"

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    string egzaminoRez;
    string* ndRez;
    string ndKiekis;
    double galutinisBalas;
};

int main() {
    string studSkaicius;

    studentuSkIvedimas:
    cout << "Studentu skaicius: ";
    cin >> studSkaicius;
    if(!isNumber(studSkaicius)){
        cout << "Studentu skaicius turi buti sveikasis skaicius. Iveskite is naujo." << endl; 
        goto studentuSkIvedimas;
    }

    studentas* visiStudentai = new studentas[stoi(studSkaicius)];
	srand(time(0));

    // input information for each student
    for (int i = 0; i < stoi(studSkaicius); i++) {
        string atsitiktiniaiRez;

        cout << "iveskite " << i + 1 << " studento informacija:" << endl;
        cout << "Vardas: ";
        cin >> visiStudentai[i].vardas;
        cout << "Pavarde: ";
        cin >> visiStudentai[i].pavarde;

        egzaminoRezIvedimas:
        cout << "Egzamino rezultatas: ";
        cin >> visiStudentai[i].egzaminoRez;
        if(!isNumber(visiStudentai[i].egzaminoRez)){
            cout << "Egzamino rezultatas turi buti sveikasis skaicius. Iveskite is naujo." << endl; 
            goto egzaminoRezIvedimas;
        }
        if(stoi(visiStudentai[i].egzaminoRez) > 10 || stoi(visiStudentai[i].egzaminoRez) < 1){
            cout << "Egzamino rezultatas turi buti tarp 1 ir 10. Iveskite is naujo." << endl;
        }
       


        cout << "Ar generuoti namu darbu rezultatus atsitiktinai? 't' jei taip, bet kas kitas jei ne: ";
        cin >> atsitiktiniaiRez;

        NDIvedimas:
        cout << "Namu darbu kiekis: ";
        cin >> visiStudentai[i].ndKiekis;
        if(!isNumber(visiStudentai[i].ndKiekis)){
            cout << "Namu darbu kiekis turi buti sveikasis skaicius. Iveskite is naujo." << endl; 
            goto NDIvedimas;
        }
        
        int bendrasNDbalas = 0;

        if(atsitiktiniaiRez == "t"){
            visiStudentai[i].ndRez = new string[stoi(visiStudentai[i].ndKiekis)];
            for (int j = 0; j < stoi(visiStudentai[i].ndKiekis); j++) {
                visiStudentai[i].ndRez[j] = rand() % 10 + 1;
                bendrasNDbalas = stoi(visiStudentai[i].ndRez[j]) + bendrasNDbalas;
            }
        } else{
            visiStudentai[i].ndRez = new string[stoi(visiStudentai[i].ndKiekis)];

            for (int j = 0; j < stoi(visiStudentai[i].ndKiekis); j++) {
                uzdRezIvedimas:
                cout << "Rezultatas uzduoties " << j + 1 << ": ";
                cin >> visiStudentai[i].ndRez[j];
                if(!isNumber(visiStudentai[i].ndRez[j])){
                    cout << "Uzduoties rezultatas turi buti sveikasis skaicius. Iveskite is naujo." << endl;
                    goto uzdRezIvedimas;
                } else {
                    bendrasNDbalas = bendrasNDbalas + stoi(visiStudentai[i].ndRez[j]);
                }
            }
        }
        visiStudentai[i].galutinisBalas = (double)bendrasNDbalas/stoi(visiStudentai[i].ndKiekis) * 0.4 + (double)(stoi(visiStudentai[i].egzaminoRez) * 0.6);
    }

    for(int i = 0; i < stoi(studSkaicius); i++){
        cout << "------------" << endl;
        cout << "vardas: " << visiStudentai[i].vardas << endl;
        cout << "pavarde: " << visiStudentai[i].pavarde << endl;
        cout << "Balas: " << visiStudentai[i].galutinisBalas << endl;
        cout << endl;
    }


    for (int i = 0; i < stoi(studSkaicius); i++) {
        delete[] visiStudentai[i].ndRez;
    }
    delete[] visiStudentai;

    return 0;
}