#include <iostream>
#include <ctime>
using namespace std;

typedef bool (*TMatchF)(long number);
bool odd(long n) { return n%2; }

int findFirstIndex(const long ar[], int L, TMatchF mf) {
    for (int i = 0; i < L; ++i)
        if (mf(ar[i]))
            return i;
    return -1;
}

int main() {
    srand(time(NULL));
    const int LenAr = 7;
    long ar[LenAr];
    for (long &elm : ar)
        cout <<  (elm = rand() % 20 - 5)  << ' ';
    cout << endl;

    int pos = findFirstIndex(ar,LenAr,odd);
    if (pos < 0) cout << "Няма нечетни.\n";
    else cout << "Индекс на 1-о нечетно число: " << pos << endl;

    TMatchF fNeg = [](long n){ return n<0; };
    pos = findFirstIndex(ar,LenAr,fNeg);
    if (pos < 0) cout << "Няма отрицателни.\n";
    else cout << "Индекс на 1-о отрицателно: " << pos << endl;
}