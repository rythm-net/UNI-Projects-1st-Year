#include <iostream>
#include <cstring>
using namespace std;

int countSub1(const char * s, char c) {
    int num = 0;
    for (int i = 0; s[i]; ++i)
        num += s[i] == c;
    return num;
}

int countSub2(const char * s, char c) {
    int num = 0;
    char * p = strchr(s, c);
    while (p) {
        ++num;
        p = strchr(p + 1, c);
    }
    return num;
}

int countChar3(const char * s, char c) {
    int num = 0;
    for (char * p = strchr(s, c); p; ++num)
        p = strchr(p + 1, c);
    return num;
}

int main() {
    int const maxStrLen = 100;
    char ch, str[1 + maxStrLen];
    cout << "Търсен знак: ";
    cin >> ch;
    cin.getline(str, 1 + maxStrLen);
    // горното четене премахва знака '\n' от буфера на клавиатурата
    cout << "Низ (до " << maxStrLen << " знака): ";
    cin.getline(str, 1 + maxStrLen);
    cout << '\'' << ch << "\' се среща в низа \"" << str
         << "\" на " << countSub1(str, ch) << " места.\n";
    cout << '\'' << ch << "\' се среща в низа \"" << str
         << "\" на " << countSub2(str, ch) << " места.\n";
    cout << '\'' << ch << "\' се среща в низа \"" << str
         << "\" на " << countChar3(str, ch) << " места.\n";
}