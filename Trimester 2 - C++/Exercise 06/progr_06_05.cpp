#include <iostream>
using namespace std;
typedef long long elmType;

elmType R(int k) {
    if (k < 18) return k * (k+3) / 2 - 1;
    int j;
    if ( k/3.0 == (j=k/3) ) return R(2*j+4) + R(j) - 6*j;
    return R(k-7) + k - 11;
}

int main() {
    int n;
    do {
        cout<<"Номер от 1 до 999888: ";
        cin>>n;
    } while( n<1 || 999888<n );

    elmType * ar = new elmType[n];
    for(int k=1, j; k<=n; ++k)
        if( k < 18 ) ar[k-1] = k * (k+3) / 2 - 1;
        else if( k/3.0 == (j=k/3) )
            ar[k-1] = ar[2*j+4 - 1] + ar[j - 1] - 6*j;
        else ar[k-1] = ar[k-7 - 1] + k - 11;
    cout << "R( " << n << " ) = " << ar[n-1] << endl;
    delete[] ar;
    ar=NULL;
    cout << "R( " << n << " ) = " << R(n) << endl;
}