#include <iostream>
#include <string>
using namespace std;

void generateString( const string & s1, const string & s2, string & newS ) {
    newS = "";
    for( char ch : s1 )
        if( string::npos == s2.find(ch) )
            newS.push_back(ch);
}

int main() {
    string firstStr, secondStr, newString;
    cout << "1-и низ: ";
    getline(cin, firstStr);
    cout << "2-и низ: ";
    getline(cin, secondStr);

    cout << "  1-и низ: \"" << firstStr << "\"\n";
    cout << "  2-и низ: \"" << secondStr << "\"\n";

    // ******** начини чрез функция *********
    generateString(firstStr, secondStr, newString);
    cout << "Резултат: \"" << newString << "\"\n";

    // ********* начин без функция *********
    newString = "";
    for( char ch : firstStr )
        if( string::npos == secondStr.find(ch) )
            newString.push_back(ch);
    cout << "Резултат: \"" << newString << "\"\n";
}