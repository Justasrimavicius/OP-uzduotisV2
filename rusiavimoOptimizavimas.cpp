#include "functions.h"
#include "customVector.h"
#include "compare.h"
#include <algorithm>

int main(){
    string temp;
    string generateFiles;
    string conteinerType;
    vector<double> pirmosOptimizacijosLaikai;
    vector<double> antrosOptimizacijosLaikai;

    cout << "Ka daryti su programa? 'g' - generuoti studentu failus, 'v' - vektoriaus konteinerio pasirinktu algoritmu testavimas, bet kas kitas - testuoti visu tipu konteineriu optimizacijos budus." << endl;
    cin >> generateFiles;
    if(generateFiles == "g"){
        for(int i = 1000; i <= 1000000; i = i * 10){
            generateFile(to_string(i), "10");
        }
    } else if(generateFiles == "v"){
        for(int i = 1000; i <= 100000; i = i * 10){
            customVector<studentas> visiStudentaiVEC; 
            customVector<studentas> geriStudentaiVEC;
            
            duomenysIsFailo(visiStudentaiVEC, "studentai"+to_string(i));

            auto t1startVEC = chrono::high_resolution_clock::now();
            
            int j = 0;
            while (j < visiStudentaiVEC.size()) {
                if (visiStudentaiVEC.at(j).getGalutinisBalas() >= 5) {
                    geriStudentaiVEC.push_back(visiStudentaiVEC.at(j));
                    visiStudentaiVEC.erase(visiStudentaiVEC.begin() + j);
                } else {
                    j++;
                }
            }

            auto t1endVEC = chrono::high_resolution_clock::now();

            std::chrono::duration<double> t1_durVEC = t1endVEC - t1startVEC;
            pirmosOptimizacijosLaikai.push_back(t1_durVEC.count());
        }
        for(int i = 1000; i <= 100000; i = i * 10){
            customVector<studentas> visiStudentaiVEC; 
            customVector<studentas> geriStudentaiVEC;
            
            duomenysIsFailo(visiStudentaiVEC, "studentai"+to_string(i));
            cout << visiStudentaiVEC.size() << endl;
            auto t1startVEC = chrono::high_resolution_clock::now();
        
            auto it = stable_partition(visiStudentaiVEC.begin(), visiStudentaiVEC.end(), [](const studentas& student){
                return student.getGalutinisBalas() >= 5;
            });

            remove_copy_if(visiStudentaiVEC.begin(), it, back_inserter(geriStudentaiVEC), [] (const studentas& student){
                return student.getGalutinisBalas() < 5;
            });

            // visiStudentaiVEC.erase(visiStudentaiVEC.begin(), it);

            auto t1endVEC = chrono::high_resolution_clock::now();

            std::chrono::duration<double> t1_durVEC = t1endVEC - t1startVEC;
            antrosOptimizacijosLaikai.push_back(t1_durVEC.count());
        }

        int size = 100;
        for(int i = 0; i < pirmosOptimizacijosLaikai.size(); i++){
            size = size * 10;
            cout << "Rusiavimo didejimo tvarka greitis(" << size << "):" << endl;
            cout << "Iprastas greitis: " << fixed << setprecision(5) << pirmosOptimizacijosLaikai.at(i) << "s" << endl;
            cout << "Greitis pritaikius algoritmus: " << fixed << setprecision(5) << antrosOptimizacijosLaikai.at(i) << "s" << endl;
            cout << "1 optimizacijos laikas: 100%. 2 optimizacijos laikas, lyginant su 1: " << fixed << setprecision(2) << antrosOptimizacijosLaikai.at(i)/pirmosOptimizacijosLaikai.at(i) * 100 << "%" << endl;
        }
    }
    else {
        cout << "Koki konteinerio tipa testuoti? 'v' - vector, 'l' - list, 'd' - deque." << endl;
        cin >> conteinerType;

        // 1 optimizacijos budas - kuriami 2 konteineriai

        for(int i = 1000; i <= 100000; i = i * 10){
            if(conteinerType == "v"){
                customVector<studentas> visiStudentaiVEC;
                customVector<studentas> geriStudentaiVEC;
                customVector<studentas> blogiStudentaiVEC;
                
                duomenysIsFailo(visiStudentaiVEC, "studentai"+to_string(i));

                auto t1startVEC = chrono::high_resolution_clock::now();
                for(int j = 0; j < visiStudentaiVEC.size(); j++){
                    if(visiStudentaiVEC.at(j).getGalutinisBalas() < 5){
                        blogiStudentaiVEC.push_back(visiStudentaiVEC.at(j));
                    } else {
                        geriStudentaiVEC.push_back(visiStudentaiVEC.at(j));
                    }
                }

                auto t1endVEC = chrono::high_resolution_clock::now();

                std::chrono::duration<double> t1_durVEC = t1endVEC - t1startVEC;
                pirmosOptimizacijosLaikai.push_back(t1_durVEC.count());

            } else if(conteinerType == "l"){
                list<studentasList> visiStudentaiLIST;
                list<studentasList> geriStudentaiLIST;
                list<studentasList> blogiStudentaiLIST;
                
                duomenysIsFailoLIST(visiStudentaiLIST, "studentai"+to_string(i));

                auto t1startLIST = chrono::high_resolution_clock::now();
                for(list<studentasList>::iterator it = visiStudentaiLIST.begin(); it != visiStudentaiLIST.end(); ++it){
                    if(it->getGalutinisBalas() < 5){
                        blogiStudentaiLIST.push_back(visiStudentaiLIST.front());
                    } else {
                        geriStudentaiLIST.push_back(visiStudentaiLIST.front());
                    }
                }
                auto t1endLIST = chrono::high_resolution_clock::now();

            std::chrono::duration<double> t1_durLIST = t1endLIST - t1startLIST;
            pirmosOptimizacijosLaikai.push_back(t1_durLIST.count());

            } else if(conteinerType == "d"){

                deque<studentasDeque> visiStudentaiDEQUE;
                deque<studentasDeque> geriStudentaiDEQUE;
                deque<studentasDeque> blogiStudentaiDEQUE;

                duomenysIsFailoDEQUE(visiStudentaiDEQUE, "studentai"+to_string(i));

                auto t1startDEQUE = chrono::high_resolution_clock::now();
                for(int j = 0; j < visiStudentaiDEQUE.size(); j++){
                    if(visiStudentaiDEQUE.at(j).getGalutinisBalas() < 5){
                        blogiStudentaiDEQUE.push_back(visiStudentaiDEQUE.at(j));
                    } else {
                        geriStudentaiDEQUE.push_back(visiStudentaiDEQUE.at(j));
                    }
                }
                auto t1endDEQUE = chrono::high_resolution_clock::now();
                
                std::chrono::duration<double> t1_durDEQUE = t1endDEQUE - t1startDEQUE;
                pirmosOptimizacijosLaikai.push_back(t1_durDEQUE.count());
            }
        }

        // 2 optimizacijos budas - kuriamas tik 1 konteineris
        for(int i = 1000; i <= 100000; i = i * 10){
            if(conteinerType == "v"){
                customVector<studentas> visiStudentaiVEC; 
                customVector<studentas> geriStudentaiVEC;
                
                duomenysIsFailo(visiStudentaiVEC, "studentai"+to_string(i));

                auto t1startVEC = chrono::high_resolution_clock::now();
                
                int j = 0;
                while (j < visiStudentaiVEC.size()) {
                    if (visiStudentaiVEC.at(j).getGalutinisBalas() >= 5) {
                        geriStudentaiVEC.push_back(visiStudentaiVEC.at(j));
                        visiStudentaiVEC.erase(visiStudentaiVEC.begin() + j);
                    } else {
                        j++;
                    }
                }

                auto t1endVEC = chrono::high_resolution_clock::now();

                std::chrono::duration<double> t1_durVEC = t1endVEC - t1startVEC;
                antrosOptimizacijosLaikai.push_back(t1_durVEC.count());

            } else if(conteinerType == "l"){
                list<studentasList> visiStudentaiLIST;
                list<studentasList> geriStudentaiLIST;
                
                duomenysIsFailoLIST(visiStudentaiLIST, "studentai"+to_string(i));

                auto t1startLIST = chrono::high_resolution_clock::now();
                for (auto it = visiStudentaiLIST.begin(); it != visiStudentaiLIST.end(); ) {
                    auto next_it = std::next(it);
                    if (it->getGalutinisBalas() >= 5) {
                        geriStudentaiLIST.push_back(std::move(*it));
                        visiStudentaiLIST.erase(it);
                    }
                    it = next_it;
                }

                auto t1endLIST = chrono::high_resolution_clock::now();

            std::chrono::duration<double> t1_durLIST = t1endLIST - t1startLIST;
            antrosOptimizacijosLaikai.push_back(t1_durLIST.count());

            } else if(conteinerType == "d"){

                deque<studentasDeque> visiStudentaiDEQUE;
                deque<studentasDeque> geriStudentaiDEQUE;

                duomenysIsFailoDEQUE(visiStudentaiDEQUE, "studentai"+to_string(i));

                auto t1startDEQUE = chrono::high_resolution_clock::now();
                int j = 0;
                while (j < visiStudentaiDEQUE.size()) {
                    if (visiStudentaiDEQUE.at(j).getGalutinisBalas() >= 5) {
                        geriStudentaiDEQUE.push_back(visiStudentaiDEQUE.at(j));
                        visiStudentaiDEQUE.erase(visiStudentaiDEQUE.begin() + j);
                    } else {
                        j++;
                    }
                }
                auto t1endDEQUE = chrono::high_resolution_clock::now();
                
                std::chrono::duration<double> t1_durDEQUE = t1endDEQUE - t1startDEQUE;
                antrosOptimizacijosLaikai.push_back(t1_durDEQUE.count());
            }
  
    }
    
    int size = 100;
        for(int i = 0; i < pirmosOptimizacijosLaikai.size(); i++){
            size = size * 10;
            cout << "Rusiavimo didejimo tvarka greitis(" << size << "):" << endl;
            cout << conteinerType << " - 1 optimizacija: " << fixed << setprecision(5) << pirmosOptimizacijosLaikai.at(i) << "s" << endl;
            cout << conteinerType << " - 2 optimizacija: " << fixed << setprecision(5) << antrosOptimizacijosLaikai.at(i) << "s" << endl;
            cout << "1 optimizacijos laikas: 100%. 2 optimizacijos laikas, lyginant su 1: " << fixed << setprecision(2) << antrosOptimizacijosLaikai.at(i)/pirmosOptimizacijosLaikai.at(i) * 100 << "%" << endl;
        }
}
}