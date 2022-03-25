#include <iostream>
#include <cstring>
using namespace std;

const char spaceAndBgLetter[] = " абвгдежзийклмнопрстуфхцчшщъьюя"
                                "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЮЯ",
// spaceAndBgLetter + 1 е низа от букви
// spaceAndBgLetter + 31 е низа от големи букви
bgLetter[] = "абвгдежзийклмнопрстуфхцчшщъьюя";
bool isName(const char * name) {
    // връща true, точно когато name е правилен низ от имена
    // самият указател name не е константа (използва се по-надолу)
    if (! name            // няма низ (name==NULL)
            || 0 == *name // празен низ
            || strspn(name, spaceAndBgLetter) != strlen(name) )
            // има знак, различен от интервал и от българска буква
        return false;

    name += strspn(name, " "); //към началото на поредно име в низа
    int num = 0; // брой на намерените отделни имена в низа
    while ( * name ) { // докато има нова първа буква от име в низа
        ++num;         // намерено е още едно име в низа
        if (*name < 'А' || 'Я' < *name)
            return false; // поредното име не започва с голяма буква
        name += 1 + strspn(name + 1, bgLetter);
        // насочва next към 1-я знак след *next,
        // който не е малка българска буква
        if ( * name ) // има нещо след поредното име в низа
        {
            if (' ' != *name)
                return false; // след името има голяма буква
            // поредното име в низа е правилно
            name += strspn(name, " ");
            // към началото на следващо име;
            // прескача всички интервали
        }
    }
    return num > 2; // според броя на намерените имена в низа
}

void initials(const char * name, char * result, int mem) {
    // връща в Result низ от инициали;
    // работи само с правилни имена;
    // mem е наличната памет в result
    size_t posFrom // индекс на началото на поредното име в name
            = strspn(name, " "),
            posTo = 0; // индекс за записване в result
    while ( name[posFrom] // има поредно име за обработка
            && mem > 3) {// има място за записване на инициал
        result[posTo++] = name[posFrom];
        result[posTo++] = '.';
        result[posTo++] = ' ';
        mem -= 3;
        posFrom += 1 + strcspn( name + posFrom + 1,
                                spaceAndBgLetter + 31 );
        // прескача всичко, което не е голяма буква
    }
    result[posTo] = 0;
}

int main() {
    int const maxStrLen = 100;
    char name[1 + maxStrLen];
    do {
        cout << "Съдържащ низ: ";
        cin.getline(name, 1 + maxStrLen);
    } while ( ! isName(name) );

    char result[1 + maxStrLen];
    initials(name, result, 1 + maxStrLen);
    cout << "Инициали: " << result << endl;
}