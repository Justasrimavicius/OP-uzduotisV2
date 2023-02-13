using namespace std;

#include <cctype>
#include <iostream>
#include "iomanip"
#include <cstdlib>
#include <ctime>
#include <time.h>

bool isNumber(const string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}