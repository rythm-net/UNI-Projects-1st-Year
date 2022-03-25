#include <iostream>
#include <cstring>
using namespace std;

void generateString1(const char *s1, const char *s2, char *newS) {
    // предполага се, че има достатъчно памет за newS
    for( ; *s1 ; ++s1 )
        if( ! strchr(s2,*s1) )
            *newS++ = *s1;
    *newS = 0;
}

void generateString2( const char *s1, const char *s2, char *newS, int mem ) {
    // mem е паметта, налична за запис в newS
    for( ; *s1 && mem > 1 ; ++s1 )
        if( ! strchr(s2,*s1) )
            --mem,
                    *newS++ = *s1;
    *newS = 0;
}

int main() {
    const int maxStrLen = 100;
    char firstStr[1 + maxStrLen], secondStr[1 + maxStrLen],
            newString[1 + maxStrLen];
    cout << "1-и низ (до " << maxStrLen << " знака): ";
    cin.getline(firstStr, 1 + maxStrLen);
    cout << "2-и низ (до " << maxStrLen << " знака): ";
    cin.getline(secondStr, 1 + maxStrLen);

    cout << "  1-и низ: \"" << firstStr << "\"\n";
    cout << "  2-и низ: \"" << secondStr << "\"\n";

    // ******** начини чрез функция *********
    generateString1(firstStr, secondStr, newString);
    cout << "Резултат: \"" << newString << "\"\n";
    generateString2(firstStr, secondStr, newString, 1 + maxStrLen);
    cout << "Резултат: \"" << newString << "\"\n";

    // ********* начин без функция *********
    char  * newS = newString;
    for( char * s1 = firstStr; *s1 ; ++s1 )
        if( ! strchr(secondStr,*s1) )
            *newS++ = *s1;
    *newS = 0;
    cout << "Резултат: \"" << newString << "\"\n";
}