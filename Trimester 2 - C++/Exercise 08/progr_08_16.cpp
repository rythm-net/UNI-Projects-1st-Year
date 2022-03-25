#include <iostream>
#include <string>
using namespace std;

void replaceLeft( string & s1,const string & s2,const string & s3 ) {
    size_t pos = s1.find(s2);
    if ( string::npos != pos )
        s1.replace(pos, s2.length(), s3);
}

bool twoPos(const string & s) {
    for (size_t i = 0; i < s.length(); ++i)
        if ( s.rfind(s[i]) > i )
            return true;
    return false;
}

int main() {
    string s1, s2, s3;
    cout << "1-и низ (съдържащ): ";
    getline(cin, s1);

    do {
        cout << "2-и низ (търсен), непразен, без повторения: ";
        getline(cin, s2);
    } while (s2.length() == 0 || twoPos(s2));

    do {
        cout << "3-и низ (не съдържащ знак от \"" << s2 << "\"): ";
        getline(cin, s3);
    } while (s3.find_first_of(s2) != string::npos);

    while (s1.find(s2) != string::npos)
        replaceLeft(s1, s2, s3);
    cout << "Резултат: \"" << s1 << "\"\n";
}