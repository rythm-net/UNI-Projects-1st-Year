#include <iostream>
#include <string>
using namespace std;

const int number = 5;
const string spaceAndBgLetters=" абвгдежзийклмнопрстуфхцчшщъьюя"
                                "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЮЯ",
             BgLetters = spaceAndBgLetters.substr(1);
struct TS {     // за представяне на хранителна стока
                // продавана на тегло
  string name;  // название на стоката
  double price; // цена лв/кг
};

void readStruct(TS & s) {
  do {
    cout << "    цена: ";
    cin >> s.price;
  } while (s.price <= 0.0);

  getline(cin, s.name); // изчиства буфера на клавиатурата
  do {
    cout << "    название: ";
    getline(cin, s.name);
  } while (    s.name.length() == 0
            || BgLetters.find(s.name[0]) == string::npos
            || BgLetters.find(s.name.back()) == string::npos
            || string::npos
               != s.name.find_first_not_of(spaceAndBgLetters));
}

void writeStruct(const TS & s) {
  cout << "  " << s.name << " с цена " << s.price << " лв/кг\n";
}

void readArray(TS a[], int L) {
  cout << "Въведете данните за " << L << " стоки:\n";
  for (int i = 0; i < L; ++i) {
    cout << "  за " << i + 1 << "-а стока:\n";
    readStruct(a[i]);
  }
}

void writeArray(const TS a[], int L) {
  cout << "Масив от стоки:\n";
  for (int i = 0; i < L; ++i) writeStruct(a[i]);
}

void viewStructWithChar(const TS a[], int L, char c) {
  cout << "Структури с название, съдъжащо знак \'"
       << c << "\':\n";
  for (int i = 0; i < L; ++i)
    if ( string::npos != a[i].name.find(c) )
      writeStruct(a[i]);
  cout << "(край на справката)\n";
}

void viewStructWithEnd(const TS a[], int L, const string & end) {
  cout << "Структури с название с окончание \""
       << end << "\":\n";
  for (int i = 0; i < L; ++i) {
    size_t pos = a[i].name.rfind(end); // от 0 до string::npos
    if ( string::npos != pos // намерен е подниз end
         && pos+end.length() == a[i].name.length() // окончание е
       )
      writeStruct(a[i]);
  }
  cout << "(край на справката)\n";
}

void sortTwoKeys(TS a[], int L) {
  for (int pos = L - 1; 0 < pos; --pos) {
    int iLast = pos;
    for (int i = 0; i < pos; ++i)
      if ( a[i].price > a[iLast].price
           || a[i].price == a[iLast].price
              && a[i].name < a[iLast].name
         )
        iLast = i;
    if (pos != iLast) {
      TS temp = a[pos];
      a[pos] = a[iLast];
      a[iLast] = temp;
    }
  }
}

int main() {
  TS ar[number];
  readArray(ar, number);
  sortTwoKeys(ar, number);
  writeArray(ar, number);
  char ch;
  string endOfName;

  do {
    cout << "Знак, срещан в названието: ";
    getline(cin, endOfName);
  } while (endOfName.length() == 0);

  ch = endOfName[0];
  viewStructWithChar(ar, number, ch);
  cout << "Окончание на название: ";
  getline(cin, endOfName);
  viewStructWithEnd(ar, number, endOfName);
}