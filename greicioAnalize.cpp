#include "functions.h"
#include <chrono>

int main(){
    string temp;
    string generateFiles;
    
    cout << "Ar generuoti studentu failus? 't' - taip, bet kas kitas ne." << endl;
    cin >> generateFiles;
    if(generateFiles == "t"){
        for(int i = 1000; i <= 10000000; i = i * 10){
            generateFile(to_string(i), "10");
        }
        // 
    } else {
        for(int i = 1000; i <= 10000000; i = i * 10){
            
            auto t1start = chrono::high_resolution_clock::now(); // visos programos greicio startas
            
            customVector<studentas> visiStudentai;
            customVector<studentas> geriStudentai;
            customVector<studentas> blogiStudentai;
            
            auto t2start = chrono::high_resolution_clock::now(); // 3 testas - duomenu nuskaitymas pradzia
            duomenysIsFailo(visiStudentai, "studentai"+to_string(i));
            auto t2end = chrono::high_resolution_clock::now(); // 3 testas - pabaiga
        
            auto t3start = chrono::high_resolution_clock::now(); // 4 testas - studentu rusiavimas i dvi grupes pradzia
            sortStudents(visiStudentai, geriStudentai, blogiStudentai);
            auto t3end = chrono::high_resolution_clock::now(); // 4 testas pabaiga

            auto t4start = chrono::high_resolution_clock::now(); // 5 testas - studentu isvedimas i du failus pradzia
            outputFile("studentai"+to_string(i)+"blogi", blogiStudentai);
            outputFile("studentai"+to_string(i)+"geri", geriStudentai);
            auto t4end = chrono::high_resolution_clock::now(); // 5 testas pabaiga
            
            auto t1end = chrono::high_resolution_clock::now(); // visos programos greicio pabaiga
            
            std::chrono::duration<double> t1_dur = t1end - t1start;
            std::chrono::duration<double> t2_dur = t2end - t2start;
            std::chrono::duration<double> t3_dur = t3end - t3start;
            std::chrono::duration<double> t4_dur = t4end - t4start;

            cout << "Visos programos" << "(studentai" + to_string(i) + ".txt failo)" << " veikimo greitis: " << t1_dur.count() << "s" << endl;
            cout << "Duomenu nuskaitymo greitis: " << t2_dur.count() << "s" << endl;
            cout << "Studentu atskirimo i blogus ir gerus greitis: " << t3_dur.count() << "s" << endl;
            cout << "Studentu rasymo i du failus greitis: " << t4_dur.count() << "s" << endl;

            cout << "Testi laiko testavima? Spauskite bet kuria raide." << endl;
            cin >> temp;
            // visos programos greicio pabaiga
        }
    }

}