#include <iostream>
using namespace std;

int main() {
    double * u;
    u = new double;
    cout << "Число: ";
    cin >> *u;
    cout << "Прочетено: " << *u << endl;
    delete u;
    u = NULL;
    if(u) cout << "Прочетено: " << *u << endl;
}