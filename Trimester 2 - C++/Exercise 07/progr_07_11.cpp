#include <iostream>
#include <cstring> // за функции за работа с низове от тип char*
#include <string> // за функции за работа с низове от тип string
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int Len = 1 + rand() % 10;

    // с низове от тип char*
    const char bgSCh[] = "аиожхщ";
    char sCh[11]; // един знак повече заради нулевия байт след низа
    for (int i = 0; i < Len; ++i)
        sCh[i] = bgSCh[ rand() % strlen(bgSCh) ];
    sCh[Len] = 0;
    cout << '\"' << sCh << "\"\n";

    // с низове от тип string
    const string bStr = "аиожхщ";
    string str = "";
    for (int i = 0; i < Len; ++i)
        str += bStr[ rand() % bStr.length() ];
    cout << '\"' << str << "\"\n";
}