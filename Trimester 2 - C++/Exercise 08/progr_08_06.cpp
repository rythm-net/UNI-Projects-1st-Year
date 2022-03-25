#include <iostream>
#include <string>
using namespace std;

int countChar1(string s, char c) {
    int num = 0;
    for (int i = s.length() - 1; i >= 0; --i)
        num += s[i] == c;
    return num;
}

int countChar2(const string & s, char c) {
    int num = 0;
    size_t pos = s.find(c);
    while (string::npos != pos) {
        ++num;
        pos = s.find(c, pos + 1);
    }
    return num;
}

int countChar3(const string & s, char c) {
    int num = 0;
    for (size_t pos = s.find(c); string::npos != pos; ++num)
        pos = s.find(c, pos + 1);
    return num;
}

int main() {
    string str;
    char ch;
    cout << "Преброяван знак: ";
    cin >> ch;
    getline(cin, str); // изчистване на буфера на клавиатурата
    cout << "Низ: ";
    getline(cin, str);
    cout << '\'' << ch << "\' се среща в низа \"" << str
         << "\" на " << countChar1(str, ch) << " места.\n";
    cout << '\'' << ch << "\' се среща в низа \"" << str
         << "\" на " << countChar2(str, ch) << " места.\n";
    cout << '\'' << ch << "\' се среща в низа \"" << str
         << "\" на " << countChar3(str, ch) << " места.\n";
}