#include <iostream>
#include <fstream> // за достъп до файлове
#include <iomanip> // за setw
#include <ctime> // за time
#include <string>
using namespace std;

const auto fileName = "file-demo-10-01.txt";
const int width = 5, module = 20;

int main() {
    srand(time(NULL));
    ofstream outF;
    /* // флагове за отваряне на файл
       in=1 // отваряне за четене
       out=2 // отваряне за запис
       ate=4 // отваряне и позициониране в края на файла
       app=010 // отваряне за запис след края на файла
       trunc=020 // отваряне и унищожаване на предишното съдържание
       nocreate=040 // неуспех, когато файлът не съществува
       noreplace=0100 // неуспех, когато файлът съществува
    */
    outF.open(fileName); // отваряне; подразбира се ios::out
    if (!outF) {
        cout << "Не може да се отвори файл с название \""
             << fileName << "\".\n";
        exit(0);
    }

    for (int r = 1; r <= 3; ++r) {
        for (int c = 1; c <= 7; ++c)
            outF << setw(width) << rand() % module;
        outF << endl;
    }

    outF.close(); // принудително затваряне на файла
    // Файлът би бил затворен по поодразбиране,
    // при достигането на края на областта на валидност на outF.
    outF.open(fileName, ios::app); // отваряне за дописване
    outF << "-------\n";

    for (int r = 1; r <= 3; ++r) {
        for (int c = 1; c <= 5; ++c)
            outF << setw(width) << rand() % module;
        outF << endl;
    }

    outF.close(); // принудително затваряне на файла
    ifstream inF(fileName); // отваряне; подразбира се ios::in
    string str;
    int i = 1;
    while ( getline(inF, str) )
        cout << "ред " << setw(2) << i++
             << ":  \"" << str << "\"\n";
    // по подразбиране се затваря inF
    // в края на областта на валидност на inF
}