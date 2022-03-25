#include <iostream>
#include <cstring>
using namespace std;

int countSub1(const char * s, const char * sub) {
    if( NULL == sub || 0 == *sub ) // търси се празен низ или нищо
        return 1 + strlen(s);
    int num = 0;
    char * p = strstr(s, sub);
    while (p) {
        ++num;
        p = strstr(p + 1, sub);
    }
    return num;
}

int countSub2(const char * s, const char * sub) {
    if( NULL == sub || 0 == *sub ) // търси се празен низ или нищо
        return 1 + strlen(s);
    int num = 0;
    for (char * p = strstr(s, sub); p; ++num)
        p = strstr(p + 1, sub);
    return num;
}

int main() {
    int const maxStrLen = 100;
    char str[1 + maxStrLen], sub[1 + maxStrLen];
    cout << "Съдържащ низ (до " << maxStrLen << " знака): ";
    cin.getline(str, 1 + maxStrLen);
    cout << "Подниз (до " << maxStrLen << " знака): ";
    cin.getline(sub, 1 + maxStrLen);
    cout << '\"' << sub << "\" се среща в низа \"" << str
         << "\" на " << countSub1(str, sub) << " места.\n";
    cout << '\"' << sub << "\" се среща в низа \"" << str
         << "\" на " << countSub2(str, sub) << " места.\n";
}