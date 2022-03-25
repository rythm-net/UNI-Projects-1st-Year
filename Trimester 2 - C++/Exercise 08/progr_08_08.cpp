#include <iostream>
#include <string>
using namespace std;

int countSubstring1(const string & s1, const string & s2) {
    int num = 0;
    size_t pos = s1.find(s2);
    while (string::npos != pos) {
        ++num;
        pos = s1.find(s2, pos + 1);
    }
    return num;
}

int countSubstring2(string s1, string s2) {
    int num = 0;
    for (size_t pos = s1.find(s2); string::npos != pos; ++num)
        pos = s1.find(s2, pos + 1);
    return num;
}

int main() {
    string str, sub;
    cout << "Съдържащ низ: ";
    getline(cin, str);
    cout << "Подниз: ";
    getline(cin, sub);
    cout << '\"' << str << "\" съдържа на "
         << countSubstring1(str, sub)
         << " места подниз \"" << sub << "\".\n";
    cout << '\"' << str << "\" съдържа на "
         << countSubstring2(str, sub)
         << " места подниз \"" << sub << "\".\n";
}