#include <iostream>
#include <ctime>
using namespace std;

void writeArray(const long a[], int L) {
    for (int i = 0; i < L; ++i) cout << "  " << a[i];
    cout << endl;
}

void sortUpRemainder(long a[], int L, long remainder) {
    for (int pos = L - 1; 0 < pos; --pos) {
        int iMax = pos;
        for (int i = 0; i < pos; ++i)
            if (a[i] % remainder > a[iMax] % remainder)
                iMax = i;
        long elm = a[pos];
        a[pos] = a[iMax];
        a[iMax] = elm;
    }
}

int main() {
    srand(time(NULL));
    int const Len = 15;
    long ar[Len];
    for (int i = 0; i < Len; ++i) ar[i] = rand() % 16 - 5;
    writeArray(ar, Len);
    sortUpRemainder(ar, Len, 4);
    cout<<"След подреждане според остатъка при % 4:\n";
    writeArray(ar, Len);
}