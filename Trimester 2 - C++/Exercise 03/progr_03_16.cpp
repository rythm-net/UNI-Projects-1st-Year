#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int const Len = 15;
int main() {
    srand(time(NULL));
    long long ar[Len];

    for (long long & elm : ar) elm = rand() % 201;
    for (long long elm : ar) cout << setw(4) << elm;
    cout << endl;

    for (int i = 0; i < Len; ++i) cout << setw(4) << i;
    cout << endl;

    cout << "Двойки съседни елементи с еднаква четност:\n";
    for (long long *right = ar + 1; right-ar < Len; ++right)
        if ( (bool)(*(right - 1) % 2) == (bool)(*right % 2) )
            cout << *(right - 1) << " и " << *right
                 << " с индекси " << right-ar - 1
                 << " и " << right-ar << endl;
    cout << "  (край на двойките)\n";
}