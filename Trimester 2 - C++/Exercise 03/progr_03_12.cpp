#include <iostream>
#include <iomanip>
using namespace std;

int const r = 3, c = 7;
int main() {
    long t[r][c];

    for(int r0=0, c0=c-1, N=1; r0<r; 0<c0 ? --c0 : ++r0)
        for(int r1=r0, c1=c0; r1<r && c1<c; ++r1, ++c1)
            t[r1][c1] = N++;

    for (decltype(t[0]) row : t) {
        for (long elm : row) cout << setw(5) << elm;
        cout << endl;
    }
}