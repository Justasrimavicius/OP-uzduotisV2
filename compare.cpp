#include "functions.h"
#include "compare.h"
#include <algorithm>

bool compareFunc(studentas& nr1, studentas& nr2);

int main(){
    string temp;
    string generateFiles;
    string conteinerType;

    cout << "Ar generuoti studentu failus? 't' - taip, bet kas kitas ne." << endl;
    cin >> generateFiles;
    if(generateFiles == "t"){
        for(int i = 1000; i <= 10000000; i = i * 10){
            generateFile(to_string(i), "10");
        }
    } else {
        cout << "Koki konteinerio tipa testuoti? 'v' - vector, 'l' - list, 'd' - deque." << endl;
        cin >> conteinerType;

        for(int i = 1000; i <= 10000000; i = i * 10){
            if(conteinerType == "v"){
                vector<studentas> visiStudentaiVEC;
                vector<studentas> geriStudentaiVEC;
                vector<studentas> blogiStudentaiVEC;
                
                auto t1startVEC = chrono::high_resolution_clock::now();
                duomenysIsFailo(visiStudentaiVEC, "studentai"+to_string(i));
                auto t1endVEC = chrono::high_resolution_clock::now();

                auto t2startVEC = chrono::high_resolution_clock::now(); // 2 testas - rusiavimas didejimo tvarka pradzia
                sort(visiStudentaiVEC.begin(), visiStudentaiVEC.end(), [](const studentas& nr1, const studentas& nr2){
                    if(nr1.getVardas() == nr2.getVardas()){
                        return nr1.getPavarde() < nr2.getPavarde();
                    }
                    return nr1.getVardas() < nr2.getVardas();
                });

                auto t2endVEC = chrono::high_resolution_clock::now();

                auto t3startVEC = chrono::high_resolution_clock::now();
                sortStudents(visiStudentaiVEC, geriStudentaiVEC, blogiStudentaiVEC);
                auto t3endVEC = chrono::high_resolution_clock::now();

                std::chrono::duration<double> t1_durVEC = t1endVEC - t1startVEC;
                std::chrono::duration<double> t2_durVEC = t2endVEC - t2startVEC;
                std::chrono::duration<double> t3_durVEC = t3endVEC - t3startVEC;
                cout << "Dydis:" << i << "-------------------------Konteineris:" << conteinerType << endl;
                cout << "Duomenu nuskaitymo greitis:" << endl;
                cout << "VEC: " << t1_durVEC.count() << "s" << endl;
                cout << "Rusiavimo didejimo tvarka greitis:" << endl;
                cout << "VEC: " << t2_durVEC.count() << "s" << endl;
                cout << "Skirstymo i dvi grupes greitis:" << endl;
                cout << "VEC: " << t3_durVEC.count() << "s" << endl;

            } else if(conteinerType == "l"){

                list<studentasList> visiStudentaiLIST;
                list<studentasList> geriStudentaiLIST;
                list<studentasList> blogiStudentaiLIST;
                
                auto t1startLIST = chrono::high_resolution_clock::now();
                duomenysIsFailoLIST(visiStudentaiLIST, "studentai"+to_string(i));
                auto t1endLIST = chrono::high_resolution_clock::now();

                auto t2startLIST = chrono::high_resolution_clock::now();
                visiStudentaiLIST.sort([](const studentasList& nr1, const studentasList& nr2){
                    if(nr1.getVardas() == nr2.getVardas()){
                        return nr1.getPavarde() < nr2.getPavarde();
                    }
                    return nr1.getVardas() < nr2.getVardas();
                });

                auto t2endLIST = chrono::high_resolution_clock::now();

                auto t3startLIST = chrono::high_resolution_clock::now();
                sortStudentsLIST(visiStudentaiLIST, geriStudentaiLIST, blogiStudentaiLIST);
                auto t3endLIST = chrono::high_resolution_clock::now();

            std::chrono::duration<double> t1_durLIST = t1endLIST - t1startLIST;
            std::chrono::duration<double> t2_durLIST = t2endLIST - t2startLIST;
            std::chrono::duration<double> t3_durLIST = t3endLIST - t3startLIST;
                
            cout << "Dydis:" << i << "-------------------------Konteineris:" << conteinerType << endl;
            cout << "Duomenu nuskaitymo greitis:" << endl;
            cout << "LIST: " << t1_durLIST.count() << "s" << endl;
            cout << "Rusiavimo didejimo tvarka greitis:" << endl;
            cout << "LIST: " << t2_durLIST.count() << "s" << endl;
            cout << "Skirstymo i dvi grupes greitis:" << endl;
            cout << "LIST: " << t3_durLIST.count() << "s" << endl;

            } else if(conteinerType == "d"){

                deque<studentasDeque> visiStudentaiDEQUE;
                deque<studentasDeque> geriStudentaiDEQUE;
                deque<studentasDeque> blogiStudentaiDEQUE;

                auto t1startDEQUE = chrono::high_resolution_clock::now();
                duomenysIsFailoDEQUE(visiStudentaiDEQUE, "studentai"+to_string(i));
                auto t1endDEQUE = chrono::high_resolution_clock::now();

                auto t2startDEQUE = chrono::high_resolution_clock::now();
                sort(visiStudentaiDEQUE.begin(), visiStudentaiDEQUE.end(), [](const studentasDeque& nr1, const studentasDeque& nr2){
                    if(nr1.getVardas() == nr2.getVardas()){
                        return nr1.getPavarde() < nr2.getPavarde();
                    }
                    return nr1.getVardas() < nr2.getVardas();
                });
                auto t2endDEQUE = chrono::high_resolution_clock::now();
                
                auto t3startDEQUE = chrono::high_resolution_clock::now();
                sortStudentsDEQUE(visiStudentaiDEQUE, geriStudentaiDEQUE, blogiStudentaiDEQUE);
                auto t3endDEQUE = chrono::high_resolution_clock::now();

                std::chrono::duration<double> t1_durDEQUE = t1endDEQUE - t1startDEQUE;
                std::chrono::duration<double> t2_durDEQUE = t2endDEQUE - t2startDEQUE;
                std::chrono::duration<double> t3_durDEQUE = t3endDEQUE - t3startDEQUE;

                cout << "Dydis:" << i << "-------------------------Konteineris:" << conteinerType << endl;
                cout << "Duomenu nuskaitymo greitis:" << endl;
                cout << "DEQUE: " << t1_durDEQUE.count() << "s" << endl;
                cout << "Rusiavimo didejimo tvarka greitis:" << endl;
                cout << "DEQUE: " << t2_durDEQUE.count() << "s" << endl;
                cout << "Skirstymo i dvi grupes greitis:" << endl;
                cout << "DEQUE: " << t3_durDEQUE.count() << "s" << endl;
            }
        }
    }

}





bool compareFunc(studentas& nr1, studentas& nr2){
    return strcmp(nr1.getVardas().c_str(), nr2.getVardas().c_str());
}
bool compareFuncLIST(studentasList& nr1, studentasList& nr2){
    return strcmp(nr1.getVardas().c_str(), nr2.getVardas().c_str());
}