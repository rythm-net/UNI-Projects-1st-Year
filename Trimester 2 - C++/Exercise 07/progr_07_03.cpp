#include <iostream>
#include <ctime>
using namespace std;

void setArrayRandom(long a[], int L, long min, long max) {
    for (int i = 0; i < L; ++i)
        a[i] = rand() % (max - min + 1) + min;
}

void writeArray(const long a[], int L) {
    for (int i = 0; i < L; ++i) cout << "  " << a[i];
    cout << endl;
}

void sortUpBubble(long a[], int L) {
    for (int n = 1; n <= L; ++n)
        for (int i = L - 1; 0 < i; --i)
            if (a[i - 1] > a[i]) {
                long temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
}

void sortDownSelection(long a[], int L) {
    for (int pos = L - 1; 0 < pos; --pos) {
        int iMin = pos;
        for (int i = 0; i < pos; ++i)
            if (a[i] < a[iMin])
                iMin = i;
        long temp = a[pos];
        a[pos] = a[iMin];
        a[iMin] = temp;
    }
}

void sortUpInsertion(long a[], int L) {
    for (int next = L - 2; 0 <= next; --next) {
        int pos = next;
        while (pos < L - 1 && a[next] > a[pos + 1]) ++pos;
        long elm = a[next];
        for (int i = next + 1; i <= pos; ++i) a[i - 1] = a[i];
        a[pos] = elm;
    }
}

int main() {
    srand(time(NULL));
    int const Len = 10;
    long ar[Len];
    setArrayRandom(ar, Len, -3, 5);
    writeArray(ar, Len);
    sortUpBubble(ar, Len);
    writeArray(ar, Len);
    sortDownSelection(ar, Len);
    writeArray(ar, Len);
    sortUpInsertion(ar, Len);
    writeArray(ar, Len);
}