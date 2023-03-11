
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

using namespace std;

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::string egzaminoRez;
    std::vector<std::string> ndRez;
    std::string ndKiekis;
    double galutinisBalas;
};

bool isNumber(const std::string &s);

void merge(std::vector<studentas>& arr, int l, int m, int r);
 
void mergesort(std::vector<studentas>& arr, int l, int r);

void duomenysIsFailo(vector<studentas>& visiStudentai, string fileName);

int generateFile(string studKiekis, string ndKiekis);

void sortStudents(vector<studentas> visiStudentai, vector<studentas>& geri, vector<studentas>& blogi);

void outputFile(string fileName, vector<studentas>& vector);