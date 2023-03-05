
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

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::string egzaminoRez;
    std::vector<std::string> ndRez;
    std::string ndKiekis;
    double galutinisBalas;
};

bool isNumber(const std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

// int partition(std::vector<studentas>& arr, int low, int high){
//     studentas pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j <= high - 1; j++) {
//         if (strcmp((arr[j].vardas).c_str(), (pivot.vardas).c_str()) < 0) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         } else if(strcmp((arr[j].vardas).c_str(), (pivot.vardas).c_str()) == 0){
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// void quicksort(std::vector<studentas>& arr, int low, int high){
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quicksort(arr, low, pi - 1);
//         quicksort(arr, pi + 1, high);
//     }
// }
void merge(std::vector<studentas>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    std::vector<studentas> L(n1), R(n2);
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i].vardas <= R[j].vardas){
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
 
void mergesort(std::vector<studentas>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
