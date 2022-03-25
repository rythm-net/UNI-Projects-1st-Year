#include <iostream>
#include <cstring>
using namespace std;

char relation(const char * s1, const char * s2) {
    int r = strcmp(s1, s2);
    if (r < 0) return '<';
    if (0 == r) return '=';
    return '>';
}

int main() {
    const int maxStrLen = 100;
    char sCh1[1 + maxStrLen], sCh2[1 + maxStrLen];
    cout << "1-и низ (до " << maxStrLen << " знака): ";
    cin.getline(sCh1, 1 + maxStrLen);
    cout << "2-и низ (до " << maxStrLen << " знака): ";
    cin.getline(sCh2, 1 + maxStrLen);
    cout << '\"' << sCh1 << "\" " << relation(sCh1, sCh2)
         << " \"" << sCh2 << "\"\n";
}