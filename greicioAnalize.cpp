#include "functions.h"
#include <chrono>

int main(){
    string temp;

    for(int i = 1000; i <= 10000000; i = i * 10){
        auto t1start = chrono::high_resolution_clock::now(); // visos programos greicio startas
        
        vector<studentas> visiStudentai;
        
        auto t2start = chrono::high_resolution_clock::now(); // 2 testas - generavimas pradzia
        generateFile(to_string(i), "10");
        auto t2end = chrono::high_resolution_clock::now(); // 2 testas - pabaiga
        

        
        auto t3start = chrono::high_resolution_clock::now(); // 3 testas - duomenu nuskaitymas pradzia
        duomenysIsFailo(visiStudentai, "studentai"+to_string(i));
        auto t3end = chrono::high_resolution_clock::now(); // 3 testas - pabaiga
       
        auto t4start = chrono::high_resolution_clock::now(); // 4 testas - studentu rusiavimas i dvi grupes pradzia
        sortStudents("studentai"+to_string(i), visiStudentai);
        auto t4end = chrono::high_resolution_clock::now(); // 4 testas pabaiga
        
        auto t1end = chrono::high_resolution_clock::now(); // visos programos greicio pabaiga

        auto t1_dur = chrono::duration_cast<chrono::milliseconds>( t1end - t1start ).count();
        auto t2_dur = chrono::duration_cast<chrono::milliseconds>( t2end - t2start ).count();
        auto t3_dur = chrono::duration_cast<chrono::milliseconds>( t3end - t3start ).count();
        auto t4_dur = chrono::duration_cast<chrono::milliseconds>( t4end - t4start ).count();

        cout << "Visos programos" << "(studentai" + to_string(i) + ".txt failo)" << " veikimo greitis: " << t1_dur << "ms" << endl;
        cout << "Failo generavimo greitis: " << t2_dur << "ms" << endl;
        cout << "Duomenu nuskaitymo greitis: " << t3_dur << "ms" << endl;
        cout << "Studentu rusiavimo i du failus greitis: " << t4_dur << "ms" << endl;

        cout << "Testi laiko testavima? Spauskite bet kuria raide." << endl;
        cin >> temp;
        // visos programos greicio pabaiga
    }


}