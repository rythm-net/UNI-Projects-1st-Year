#include <iostream>
#include <cstring>
using namespace std;

void viewIndices(const char * s, const char * sub) {
    cout << "  Индекси на местата, където \"" << sub
         << "\"\n    се среща в низа \"" << s << "\": ";
    for ( char *next = strstr(s, sub);
          next;
          next = strstr(next + 1, sub) )
        cout << next - s << "  ";
    cout << endl;
}

void viewSubstrings(const char * str, char ch1, char ch2) {
    //извежда поднизовете от знакове от [ch1;ch2] и местата им в str
    cout << "Поднизове на \"" << str
         << "\" от знакове от интервала [\'"
         << ch1 << "\';\'" << ch2 << "\']:\n";
    const char * s = str;
    char * sub = new char[1 + strlen(s)];
    while (*s) // докато има знак за възможно начало на подниз
        if (*s < ch1 || ch2 < *s) ++s;
        else {
            const char * next = s + 1;
            while (*next && ch1 <= *next && *next <= ch2) ++next;
            strncpy_s(sub, 1 + next - s, s, next - s);
            cout << "Подниз: \"" << sub << "\"\n";
            viewIndices(str, sub);
            s = next;
        }
    delete[] sub;
    cout<<"(край на поднизовете)\n";
}

int main() {
    const int maxStrLen = 100;
    char str[1 + maxStrLen];
    cout << "Низ (до " << maxStrLen << " знака): ";
    cin.getline(str, 1 + maxStrLen);
    viewSubstrings(str,'a','z');
}