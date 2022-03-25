#include <iostream>
#include <ctime>
using namespace std;

void writeArray(const long a[], int L) {
    for (int i = 0; i < L; ++i) cout << "  " << a[i];
    cout << endl;
}

void setArrayRandom(long a[], int L, long min, long max) {
    for (int i = 0; i < L; ++i)
        a[i] = rand() % (max - min + 1) + min;
}

bool containAll(const long a1[], int L1, const long a2[], int L2) {
    // връща true, точно когато a1 съдържа всеки елемент на a2
    for (int i2 = 0; i2 < L2; ++i2) {
        int i1 = 0;
        while (i1 < L1 && a1[i1] != a2[i2]) ++i1;
        if (i1 == L1) return false;
    }
    return t
    rue;
}
int main() {
    srand(time(NULL));
    const int Len1 = 4, Len2 = 9;
    long ar1[Len1], ar2[Len2];
    setArrayRandom(ar1,Len1,-3,1);
    setArrayRandom(ar2,Len2,-4,3);
    cout<<"1-и масив: ";
    writeArray(ar1,Len1);
    cout<<"2-и масив: ";
    writeArray(ar2,Len2);
    if(containAll(ar2,Len2,ar1,Len1))
        cout<<"Всеки елемент на 1-я се съдържа във 2-я масив.\n";
    else
        cout<<"Някой елемент на 1-я не се съдържа във 2-я масив.\n";
    if(containAll(ar1,Len1,ar2,Len2))
        cout<<"Всеки елемент на 2-я се съдържа в 1-я масив.\n";
    else
        cout<<"Някой елемент на 2-я не се съдържа в 1-я масив.\n";
}