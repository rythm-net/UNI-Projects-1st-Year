#include <iostream>
#include <string>
using namespace std;

char relation(string s1, const string & s2) {
    int r = s1.compare(s2);
    if (r < 0) return '<';
    if (0 == r) return '=';
    return '>';
}

int main() {
    string sCh1, sCh2;
    cout << "1-и низ знака): ";
    getline(cin, sCh1);
    cout << "2-и низ знака): ";
    getline(cin, sCh2);
    cout << '\"' << sCh1 << "\" " << relation(sCh1, sCh2)
         << " \"" << sCh2 << "\"\n";
}