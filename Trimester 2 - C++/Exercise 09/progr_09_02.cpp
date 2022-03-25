#include <iostream>
#include <string>
using namespace std;

const int number = 6;
void readArStr(string a[], int L) {
    cout<<"Въведете "<<L<<" низа:\n";
    for(int i=0; i<L; ++i) {
        cout<<"  "<<i+1<<"-и низ: ";
        getline(cin, a[i]);
    }
}

void writeArStr(const string a[], int L) {
    cout<<"Масив:\n";
    for(int i=0; i<L; ++i) cout<<"  \""<<a[i]<<"\"\n";
}

void sortUp(string a[], int L) {
    for(int pos=L-1; 0<pos; --pos) {
        int iMax = pos;
        for(int i=0; i<pos; ++i)
            if( a[i] > a[iMax] ) iMax = i;
        a[iMax].swap(a[pos]);
    }
}

int main() {
    string arStr[number];
    readArStr(arStr, number);
    sortUp(arStr, number);
    writeArStr(arStr, number);
}