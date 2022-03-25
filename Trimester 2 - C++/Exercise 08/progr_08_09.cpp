#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int const maxStrLen = 100;
    char str[1 + maxStrLen], sub[1 + maxStrLen];
    cout << "Съдържащ низ (до " << maxStrLen << " знака): ";
    cin.getline(str, 1 + maxStrLen);
    cout << "Подниз (до " << maxStrLen << " знака): ";
    cin.getline(sub, 1 + maxStrLen);
    char * first = strstr(str, sub);

    if( ! first )
        cout << '\"' << sub << "\" не се среща в \""
             << str << "\".\n";
    else {
        char * next = strstr(first+1,sub),
                * next2 = next ? strstr(next+1,sub) : NULL;
        bool no2ower // резултат от търсенето
                =    ! next // не се среща втори път
                     || next2 // среща се поне три пъти
                     || next >= first + strlen(sub); // няма препокриване
        cout << "Поднизът \"" << sub << "\" "
             << (no2ower ? "не се" : "се")
             << " среща\n  точно на две препокриващи се места в \""
             << str << "\".\n";
    }
}