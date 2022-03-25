#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, sub;
    cout << "Съдържащ низ: ";
    getline(cin, str);
    cout << "Подниз: ";
    getline(cin, sub);
    size_t first = str.find(sub), Last = str.rfind(sub);

    bool no2ower // резултат от търсенето
            =    string::npos == first // не се среща нито веднъж
                 || Last == first // не се среща втори път
                 || Last != str.find(sub,first+1) // среща се поне 3 пъти
                 || Last >= first + sub.length(); // няма препокриване
    cout << "Поднизът \"" << sub << "\" "
         << (no2ower ? "не се" : "се")
         << " среща\n  точно на две препокриващи се места в \""
         << str << "\".\n";
}