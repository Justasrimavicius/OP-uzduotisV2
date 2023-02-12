using namespace std;
#include <cctype>
#include <iostream>


bool isNumber(const string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}