#include <iostream>
#include <string>
using namespace std;

void viewIndices(const string & s, const string & sub) {
    cout << "  Индекси на местата, където \"" << sub
         << "\"\n    се среща в низа \"" << s << "\": ";
    for ( size_t pos = s.find(sub);
          string::npos != pos;
          pos = s.find(sub, pos + 1)
            )
        cout << pos << "  ";
    cout << endl;
}

void viewSubstrings1(const string & str, char ch1, char ch2) {
    //извежда поднизовете от знакове от [ch1;ch2] и местата им в str
    cout << "Поднизове на \"" << str
         << "\" от знакове от интервала [\'"
         << ch1 << "\';\'" << ch2 << "\']:\n";
    size_t pos = 0;
    while ( pos < str.length() )//ако има възможно начало на подниз
        if (str[pos] < ch1 || ch2 < str[pos]) ++pos;
        else {
            size_t nextPos = pos + 1;
            while( nextPos < str.length()
                   && ch1 <= str[nextPos]
                   && str[nextPos] <= ch2
                    )
                ++nextPos;
            string sub = str.substr(pos, nextPos - pos);
            cout << "Подниз: \"" << sub << "\"\n";
            viewIndices(str, sub);
            pos = nextPos;
        }
    cout << "(край на поднизовете)\n\n";
}

void viewSubstrings2(const string & str, const string & ch) {
    // извежда поднизовете от знакове от ch1 и местата им в str
    cout << "Поднизове на \"" << str
         << "\" от знакове от низа \"" << ch << "\":\n";
    for( size_t begin = str.find_first_of(ch),after;
         string::npos != begin;
         begin = str.find_first_of(ch, after)) {
            after = str.find_first_not_of(ch, begin);
            string sub = string::npos == after
                     ? str.substr(begin)
                     : str.substr(begin, after-begin);
            cout << "Подниз: \"" << sub << "\"\n";
            viewIndices(str, sub);
    }
    cout << "(край на поднизовете)\n\n";
}

int main() {
    string str;
    cout << "Низ: ";
    getline(cin, str);
    viewSubstrings1(str, 'a', 'z');
    viewSubstrings2(str, "abcdefghijklmnopqrstuvwxyz");
}