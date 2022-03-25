#include <iostream>
using namespace std;

void readArray(double a[], int L) {
    cout << "Въведете " << L << " числа:\n";
    for (int i = 0; i < L; ++i) {
        cout << "  " << i + 1 << "-о число: ";
        cin >> a[i];
    }
}

double firstPositive(const double a[], int L) {
    for (int i = 0; i < L; ++i)
        if (a[i] > 0.0)
            return a[i];
    return -1.0;
}

int LastIndexMinimum(const double a[], int L) {
    int minInd = 0;
    for (int i = 1; i < L; ++i)
        if (a[i] <= a[minInd])
            minInd = i;
    return minInd;
}

void firstLastIndicesNegative1(const double a[], int L,
                               int & fInd, int & LInd) {
    LInd = L - 1;
    while (0 <= LInd && a[LInd] >= 0.0) --LInd;
    if (-1 == LInd) { fInd = -1; return; }
    fInd = 0;
    while (a[fInd] >= 0.0) ++fInd;
}

void firstLastIndicesNegative2(const double a[], int L,
                               int * fInd, int * LInd) {
    *LInd = L - 1;
    while (0 <= *LInd && a[*LInd] >= 0.0) -- *LInd;
    if (-1 == *LInd) { *fInd = -1; return; }
    *fInd = 0;
    while (a[*fInd] >= 0.0) ++ *fInd;
}

int main() {
    int const Len = 7;
    double ar[Len];
    readArray(ar, Len);
    double fPositiv = firstPositive(ar, Len);

    if (-1.0 == fPositiv) cout << "Няма положителен елемент.\n";
    else cout << "Първи положителен елемент: " << fPositiv << endl;
    cout << "Индекс на последния минимум: "
         << LastIndexMinimum(ar, Len) << endl;
    int first, Last;
    firstLastIndicesNegative1(ar, Len, first, Last);

    if (-1 == first) cout << "Няма отрицателни елементи.\n";
    else
        cout << "Индекси на 1-ия и последния отрицателни елементи: "
             << first << " и " << Last << endl;
    firstLastIndicesNegative2(ar, Len, &first, &Last);

    if (-1 == first) cout << "Няма отрицателни елементи.\n";
    else
        cout << "Индекси на 1-ия и последния отрицателни елементи: "
             << first << " и " << Last << endl;
}