#include <iostream>
using namespace std;

void write(long a[], int L) {
    cout << "Масив: ";
    for (int i = 0; i < L; ++i) cout << a[i] << " ";
    cout << endl;
}

bool findSequential(const long a[], int L, long num) {
    // последователно търсене по намаляване наиндексите
    int i;
    for (i = L - 1; 0 < i && a[i] > num; --i) ;
    return a[i] == num;
}

bool findBinary(const long a[], int L, long num) {
    // двоично търсене
    int first = 0, end = L - 1, m;
    while (first < end) {
        m = (first + end) / 2;
        // 0 <= first <= m < end <= L-1
        if (a[m] < num) first = m + 1;
        else end = m;
    }
    return a[first] == num;
}

int main() {
    long ar[] = { 2, 4, 4, 6, 8 };
    int const Len = sizeof(ar) / sizeof(ar[0]);
    for (int L = 1; L <= Len; ++L) {
        write(ar, L);
        cout << "    true <-- ";
        for (int n = 1; n < 10; ++n)
            if ( findSequential(ar, L, n) )
                cout << n << "  ";
        cout << endl;
        cout << "    true <-- ";
        for (int n = 1; n < 10; ++n)
            if ( findBinary(ar, L, n) )
                cout << n << "  ";
        cout << endl;
        cout << "  false <-- ";
        for (int n = 1; n < 10; ++n)
            if ( ! findSequential(ar, L, n) )
                cout << n << "  ";
        cout << endl;
        cout << "  false <-- ";
        for (int n = 1; n < 10; ++n)
            if ( ! findBinary(ar, L, n) )
                cout << n << "  ";
        cout << endl;
    }
}