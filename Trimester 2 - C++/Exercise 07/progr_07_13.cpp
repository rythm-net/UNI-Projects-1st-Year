#include <iostream>
#include <string> // за функции за работа с низове от тип string
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    string s;
    do {
        cout << "Низ с дължина от 2 нагоре: ";
        getline(cin,s);
    } while (s.length() < 2);

    string newS = "";
    for (int i = 0; i < 6; ++i)
        newS += s[rand() % s.length()];
    cout << "Генериран низ: \"" << newS << "\"\n";
}