#include <iostream>
#include <cstring> // за функции за работа с низове от тип char*
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int maxStringLen = 100;
    char s[1 + maxStringLen];
    do {
        cout << "Низ с дължина от 2 до " << maxStringLen << ": ";
        cin.getline(s, 1 + maxStringLen);
    } while (strlen(s) < 2);

    char newS[7];
    for (int i = 0; i < 6; ++i)
        newS[i] = s[rand() % strlen(s)];
    newS[6] = 0;
    cout << "Генериран низ: \"" << newS << "\"\n";
}