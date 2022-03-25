#include <iostream>
#include <string>
using namespace std;

const string bgLetterCap = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЮЯ",
        bgLetter         = "абвгдежзийклмнопрстуфхцчшщъьюя"
                         + bgLetterCap,
        bgLetterOrSpace  = bgLetter + bgLetterCap + ' ';

bool isName(const string & name) {
    // връща true, точно когато name е правилен низ от имена
    if( name.length() == 0 // празен низ
        || string::npos != name.find_first_not_of(bgLetterOrSpace) )
        // има знак, различен от интервал и от българска буква
        return false;
    size_t index // индекс на началото на поредното име в низа
            = name.find_first_not_of(' ');
    int count = 0; // брой намерени отделни имена в низа

    while (string::npos != index) {// докато има нова първа буква
        ++count; // намерено е още едно име в низа
        if (name[index] < 'А' || 'Я' < name[index])
            return false; // поредното име не започва с голяма буква
        index = name.find_first_not_of(bgLetter, index + 1);
        if (string::npos != index) // има нещо след името
        {
            if (' ' != name[index])
                return false; // след името има голяма буква
            // поредното име в низа е правилно
            index = name.find_first_not_of(' ', index + 1);
            // търси следващо име
        }
    }
    return count > 2; // според броя на намерените имена в низа
}

string initials(const string & name) {
    // връща низ от инициали; работи само с правилни имена
    string result = "";
    const string delim = ". ";
    size_t index = name.find_first_of(bgLetterCap);
    while (string::npos != index) {
        result += name[index] + delim;
        index = name.find_first_of(bgLetterCap, index + 1);
    }
    return result;
}

int main() {
    string name;
    do {
        cout << "Съдържащ низ: ";
        getline(cin, name);
    } while (!isName(name));
    cout << "Инициали: " << initials(name) << endl;
}