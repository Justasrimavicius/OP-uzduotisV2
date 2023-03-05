#include "functions.h"
#include <string>
#include <random>

using namespace std;

int main(){
    string studKiekis;
    string ndKiekis;
    int bendrasNDbalas = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    cout << "Studentu kiekis: " << endl;
    cin >> studKiekis;
    cout << "Namu darbu kiekis: " << endl;
    cin >> ndKiekis;

    if(!isNumber(studKiekis) || !isNumber(ndKiekis)){
        cout << "Ivedimas netinkamas. Bandykite is naujo." << endl;
        return 0;
    };


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