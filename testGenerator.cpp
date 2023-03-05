#include "functions.h"
#include <string>
#include <random>

using namespace std;

int generateFile();

int main(){
    string studKiekis;
    string ndKiekis;

    cout << "Studentu kiekis: " << endl;
    cin >> studKiekis;
    cout << "Namu darbu kiekis: " << endl;
    cin >> ndKiekis;

    generateFile(studKiekis, ndKiekis);
}




