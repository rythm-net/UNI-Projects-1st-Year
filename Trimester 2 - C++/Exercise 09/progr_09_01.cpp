#include <iostream>
#include <cstring>
using namespace std;

const int number = 6;
void readArStrCharPointer1(char *a, int rows, int strLen) {
  cout << "Въведете " << rows << " низа:\n";
  for (int i = 0; i < rows; ++i) {
    cout << "  " << i + 1 << "-и низ: ";
    cin.getline( & a[i * (1 + strLen)], 1 + strLen );
  }
}

void readArStrCharPointer2(char *a, int LenArChar, int rows) {
  cout<<"Въведете "<<rows<<" низа:\n";
  int LenRow = LenArChar/rows;
  for(int i=0; i<rows; ++i) {
    cout<<"  "<<i+1<<"-и низ: ";
    cin.getline(& a[i*LenRow], LenRow);
  }
}

const int maxStrLen = 100;
void readArStr(char a[][1 + maxStrLen], int L) {
    // Този вариант е за предпочитане пред горните два,
    // но изисква да бъде позната константата maxStrLen.
  cout << "Въведете " << L << " низа:\n";
  for (int i = 0; i < L; ++i) {
    cout << "  " << i + 1 << "-и низ: ";
    cin.getline(a[i], 1 + maxStrLen);
  }
}

void writeArStr(const char a[][1 + maxStrLen], int L) {
  cout << "Масив от низове:\n";
  for (int i = 0; i < L; ++i)
    cout << "  \"" << a[i] << "\"\n";
}

void sortUp(char a[][1 + maxStrLen], int L) {
  char temp[1 + maxStrLen];
  for (int pos = L - 1; 0 < pos; --pos) {
    int iMax = pos;
    for (int i = 0; i < pos; ++i)
      if (strcmp(a[i], a[iMax]) > 0)
        iMax = i;
    if (iMax != pos) {
      strcpy_s(temp, a[pos]);
      strcpy_s(a[pos], a[iMax]);
      strcpy_s(a[iMax], temp);
    }
  }
}

int main() {
  char arStr[number][1 + maxStrLen];
    //readArStrCharPointer1(arStr[0], number, maxStrLen);
    //readArStrCharPointer2(arStr[0], number*(1+maxStrLen), number);
  readArStr(arStr, number); // по-добър вариант
  sortUp(arStr, number);
  writeArStr(arStr, number);
}