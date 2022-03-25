#include <iostream>
#include <ctime>
using namespace std;

void write(long *a, int L) {
    for (int i = 0; i < L; ++i) cout << ' ' << a[i];
    cout << endl;
}

void quickSort(long ar[], int Len) {
    long elm = ar[0];
    int Left = 0, right = Len - 1;
    do {
        while (elm < ar[right]) --right;
        while (ar[Left] < elm) ++Left;
        if (Left <= right) {
            long temp = ar[Left];
            ar[Left++] = ar[right];
            ar[right--] = temp;
        }
    } while (Left < right);
    if (0 < right) quickSort(ar, right + 1);
    if (Left < Len - 1) quickSort(ar + Left, Len - Left);
}

int main() {
    srand(time(NULL));
    long ar[10];
    for (int n = 1; n < 10; ++n) {
        // от масива се използват само първите n елемента
        for (int i = 0; i < n; ++i) ar[i] = rand() % 10;
        write(ar, n);
        quickSort(ar, n);
        write(ar, n);
        cout << endl;
    }
}