#include "functions.h"
#include "customVector.h"
#include <chrono>

int main(){
    
        cout << "Laiko testavimas std::vector" << endl;

        for(int i = 10000; i <= 100000000; i = i * 10){
            
            auto t1start = chrono::high_resolution_clock::now(); // visos programos greicio startas
            std::vector<int> testVector;
            int perskirtymas = 0;
            for(int j = 0; j <= i; j++){
                testVector.push_back(j);
                if(i == 100000000 && testVector.size() == testVector.capacity())perskirtymas++;
            }
            auto t1end = chrono::high_resolution_clock::now(); // visos programos greicio pabaiga
            
            std::chrono::duration<double> t1_dur = t1end - t1start;

            cout << i << " dydis(std::vector). trukme: " << t1_dur.count() << endl;
            if(i == 100000000)cout << i << " perskirtymu kiekis: " << perskirtymas << endl;
        }

        cout << "Laiko testavimas customVector" << endl;

        for(int i = 10000; i <= 100000000; i = i * 10){
            
            auto t1start = chrono::high_resolution_clock::now(); // visos programos greicio startas
            customVector<int> testVector;
            int perskirtymas = 0;
            for(int j = 0; j <= i; j++){
                testVector.push_back(j);
                if(i == 100000000 && testVector.size() == testVector.getCapacity())perskirtymas++;
            }
            
            auto t1end = chrono::high_resolution_clock::now(); // visos programos greicio pabaiga
            
            std::chrono::duration<double> t1_dur = t1end - t1start;

            cout << i << " dydis(customVector). trukme: " << t1_dur.count() << endl;
            if(i == 100000000)cout << i << " perskirtymu kiekis: " << perskirtymas << endl;

        }
}

// compile and run: g++ -std=c++11 -o speedTest_customVectorVsStdVector speedTest_customVectorVsStdVector.cpp functions.cpp && ./speedTest_customVectorVsStdVector