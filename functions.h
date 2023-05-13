
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include "iomanip"
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cmath>
#include <vector>
#include <string>
#include <random>
#include <list>
#include <deque>

using namespace std;

class zmogus {
    protected: 
        std::string vardas;
        std::string pavarde;
    public:

        zmogus(const std::string& v, const std::string& p) : vardas(v), pavarde(p) {}

    
        virtual void dummy() = 0;

        void setVardas(const std::string& v) { vardas = v; }
        std::string getVardas() const { return vardas; }

        void setPavarde(const std::string& p) { pavarde = p; }
        std::string getPavarde() const { return pavarde; }
};


class studentas : public zmogus {
    private:
    std::string egzaminoRez;
    std::vector<std::string> ndRez;
    std::string ndKiekis;
    double galutinisBalas;
    public:
        studentas() : zmogus("", ""), egzaminoRez(""), ndRez({}), ndKiekis("0"), galutinisBalas(0) {}
        studentas(const std::string& v, const std::string& p, const std::string& e, const std::vector<std::string>& nd, const std::string& k)
            : zmogus(v, p), egzaminoRez(e), ndRez(nd), ndKiekis(k), galutinisBalas(0) {}

        // Copy constructor
        studentas(const studentas& other)
        : zmogus(other), egzaminoRez(other.egzaminoRez),
          ndRez(other.ndRez), ndKiekis(other.ndKiekis), galutinisBalas(other.galutinisBalas) {}

        // Copy assignment operator
        studentas& operator=(const studentas& other) {
            if (this != &other) {
                vardas = other.vardas;
                pavarde = other.pavarde;
                egzaminoRez = other.egzaminoRez;
                ndRez = other.ndRez;
                ndKiekis = other.ndKiekis;
                galutinisBalas = other.galutinisBalas;
            }
            return *this;
        }

        void setVardas(const std::string& v) { zmogus::setVardas(v); }
        std::string getVardas() const { return zmogus::getVardas(); }

        void setPavarde(const std::string& p) { zmogus::setPavarde(p); }
        std::string getPavarde() const { return zmogus::getPavarde(); }

        void setEgzaminoRez(const std::string& e) { egzaminoRez = e; }
        std::string getEgzaminoRez() const { return egzaminoRez; }

        void setNdRez(const std::vector<std::string>& nd) { ndRez = nd; }
        std::vector<std::string> getNdRez() const { return ndRez; }

        void setNdKiekis(const std::string& k) { ndKiekis = k; }
        std::string getNdKiekis() const { return ndKiekis; }

        double getGalutinisBalas() const { return galutinisBalas; }

        void skaiciuotiGalutiniBala() {
            double ndSuma = 0;
            for (auto& nd : ndRez) {
                ndSuma += std::stod(nd);
            }
            double egzaminoRezultatas = std::stod(egzaminoRez);
            double galutinis = 0.4 * ndSuma / ndRez.size() + 0.6 * egzaminoRezultatas;
            galutinisBalas = galutinis;
        }
        void dummy() override { }


};
class studentasList : public zmogus {
    private:
    std::string egzaminoRez;
    std::list<std::string> ndRez;
    std::string ndKiekis;
    double galutinisBalas;
    public:
        studentasList() : zmogus("", ""), egzaminoRez(""), ndRez({}), ndKiekis("0"), galutinisBalas(0) {}
        studentasList(const std::string& v, const std::string& p, const std::string& e, const std::list<std::string>& nd, const std::string& k)
            : zmogus(v, p), egzaminoRez(e), ndRez(nd), ndKiekis(k), galutinisBalas(0) {}

        // Copy constructor
        studentasList(const studentasList& other)
        : zmogus(other), egzaminoRez(other.egzaminoRez),
          ndRez(other.ndRez), ndKiekis(other.ndKiekis), galutinisBalas(other.galutinisBalas) {}

        // Copy assignment operator
        studentasList& operator=(const studentasList& other) {
            if (this != &other) {
                vardas = other.vardas;
                pavarde = other.pavarde;
                egzaminoRez = other.egzaminoRez;
                ndRez = other.ndRez;
                ndKiekis = other.ndKiekis;
                galutinisBalas = other.galutinisBalas;
            }
            return *this;
        }

        void setVardas(const std::string& v) { zmogus::setVardas(v); }
        std::string getVardas() const { return zmogus::getVardas(); }

        void setPavarde(const std::string& p) { zmogus::setPavarde(p); }
        std::string getPavarde() const { return zmogus::getPavarde(); }

        void setEgzaminoRez(const std::string& e) { egzaminoRez = e; }
        std::string getEgzaminoRez() const { return egzaminoRez; }

        void setNdRez(const std::list<std::string>& nd) { ndRez = nd; }
        std::list<std::string> getNdRez() const { return ndRez; }

        void setNdKiekis(const std::string& k) { ndKiekis = k; }
        std::string getNdKiekis() const { return ndKiekis; }

        double getGalutinisBalas() const { return galutinisBalas; }

        void skaiciuotiGalutiniBala() {
            double ndSuma = 0;
            for (auto& nd : ndRez) {
                ndSuma += std::stod(nd);
            }
            double egzaminoRezultatas = std::stod(egzaminoRez);
            double galutinis = 0.4 * ndSuma / ndRez.size() + 0.6 * egzaminoRezultatas;
            galutinisBalas = galutinis;
        }
        void dummy() override { }


};
class studentasDeque : public zmogus {
    private:
    std::string egzaminoRez;
    std::deque<std::string> ndRez;
    std::string ndKiekis;
    double galutinisBalas;
    public:
        studentasDeque() : zmogus("", ""), egzaminoRez(""), ndRez({}), ndKiekis("0"), galutinisBalas(0) {}
        studentasDeque(const std::string& v, const std::string& p, const std::string& e, const std::deque<std::string>& nd, const std::string& k)
            : zmogus(v, p), egzaminoRez(e), ndRez(nd), ndKiekis(k), galutinisBalas(0) {}

        // Copy constructor
        studentasDeque(const studentasDeque& other)
        : zmogus(other), egzaminoRez(other.egzaminoRez),
          ndRez(other.ndRez), ndKiekis(other.ndKiekis), galutinisBalas(other.galutinisBalas) {}

        // Copy assignment operator
        studentasDeque& operator=(const studentasDeque& other) {
            if (this != &other) {
                vardas = other.vardas;
                pavarde = other.pavarde;
                egzaminoRez = other.egzaminoRez;
                ndRez = other.ndRez;
                ndKiekis = other.ndKiekis;
                galutinisBalas = other.galutinisBalas;
            }
            return *this;
        }

        void setVardas(const std::string& v) { zmogus::setVardas(v); }
        std::string getVardas() const { return zmogus::getVardas(); }

        void setPavarde(const std::string& p) { zmogus::setPavarde(p); }
        std::string getPavarde() const { return zmogus::getPavarde(); }

        void setEgzaminoRez(const std::string& e) { egzaminoRez = e; }
        std::string getEgzaminoRez() const { return egzaminoRez; }

        void setNdRez(const std::deque<std::string>& nd) { ndRez = nd; }
        std::deque<std::string> getNdRez() const { return ndRez; }

        void setNdKiekis(const std::string& k) { ndKiekis = k; }
        std::string getNdKiekis() const { return ndKiekis; }

        double getGalutinisBalas() const { return galutinisBalas; }

        void skaiciuotiGalutiniBala() {
            double ndSuma = 0;
            for (auto& nd : ndRez) {
                ndSuma += std::stod(nd);
            }
            double egzaminoRezultatas = std::stod(egzaminoRez);
            double galutinis = 0.4 * ndSuma / ndRez.size() + 0.6 * egzaminoRezultatas;
            galutinisBalas = galutinis;
        }
        void dummy() override { }


};

bool isNumber(const std::string &s);

template <typename T>
void merge(T& arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    T L(n1), R(n2);
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i].getVardas() <= R[j].getVardas()){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergesort(T& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void duomenysIsFailo(vector<studentas>& visiStudentai, string fileName);

int generateFile(string studKiekis, string ndKiekis);

void sortStudents(vector<studentas> visiStudentai, vector<studentas>& geri, vector<studentas>& blogi);

void outputFile(string fileName, vector<studentas>& vector);