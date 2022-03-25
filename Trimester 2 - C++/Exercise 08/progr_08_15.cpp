#include <iostream>
#include <cstring>
using namespace std;

void replaceLeft1(char * s1, const char * s2, const char * s3) {
    // без да се променя директно низът s1
    char * first = strstr(s1, s2);
    if ( ! first ) return;
    int Len1 = strlen(s1),
            Len2 = strlen(s2),
            Len3 = strlen(s3),
            rest = 1 + Len1 - (first - s1) - Len2;
    char * copy = new char[rest];
    strcpy_s(copy, rest, first + Len2);
    strcpy_s(first, Len3 + 1, s3);
    strcpy_s(first + Len3, rest + 1, copy);
    delete[] copy;
}

void replaceLeft2(char * s1, const char * s2, const char * s3) {
    // променя се директно низът s1
    char * first = strstr(s1, s2);
    if ( ! first ) return;
    size_t Len1 = strlen(s1),
            Len2 = strlen(s2),
            Len3 = strlen(s3);
    if (Len3 > Len2)
        for ( char *p = s1 + Len1 + (Len3 - Len2);
              p >= first + Len3;
              --p )
            *p = *(p - (Len3 - Len2));
    else if (Len3 < Len2)
        for (char *p = first + Len2; p <= s1 + Len1; ++p)
            *(p - (Len2 - Len3)) = *p;
    for (int i = 0; s3[i]; ++i)
        *(first + i) = s3[i];
}

bool twoPos(const char * s) {
    for (int i = strlen(s) - 1; i > 0; --i)
        if (strchr(s, s[i]) < s + i)
            return true;
    return false;
}

int main() {
    const int maxStrLen = 100;
    char s1[1 + maxStrLen * maxStrLen],
            s2[1 + maxStrLen], s3[1 + maxStrLen];
    cout << "1-и низ (съдържащ; до " << maxStrLen << " знака): ";
    cin.getline(s1, 1 + maxStrLen);

    do {
        cout << "2-и низ (до " << maxStrLen
             << " знака), непразен, без повторения: ";
        cin.getline(s2, 1 + maxStrLen);
    } while (*s2 == 0 || twoPos(s2));

    do {
        cout << "3-и низ (без знак от \"" << s2 << "\"; до "
             << maxStrLen << " знака): ";
        cin.getline(s3, 1 + maxStrLen);
    } while (strcspn(s3, s2) != strlen(s3));

    char copy[sizeof(s1)]; // s1 е деклариран с []
    strcpy_s(copy, s1);
    while (strstr(s1, s2)) replaceLeft1(s1, s2, s3);
    cout << "Резултат: \"" << s1 << "\"\n";
    while (strstr(copy, s2)) replaceLeft2(copy, s2, s3);
    cout << "Резултат: \"" << *&copy << "\"\n";
}