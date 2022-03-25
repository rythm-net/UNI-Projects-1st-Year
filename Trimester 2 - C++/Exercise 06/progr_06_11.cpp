#include <iostream>
using namespace std;

double upY(int n, int indLast, double Last, double pred) {
    if( n <= indLast ) return 1==n ? pred : Last;
    ++indLast;
    return upY(n,
               indLast,
               indLast + Last/(indLast-1) + pred/(indLast-2),
               Last);
}

void downY(int n, double & Last, double & pred) {
    if( n<1 ) { Last=pred=0.0; return; }
    switch( n ) {
        case 1: Last=2.0; pred=0.0; return;
        case 2: Last=8.0; pred=2.0; return;
        default:
            double predPred;
            downY(n-1, pred, predPred);
            Last = n + pred/(n-1) + predPred/(n-2);
    }
}

int main() {
    int n;
    const int nMax = 500;
    do {
        cout<<"Индекс от 1 до "<<nMax<<": ";
        cin>>n;
    } while( n<1 || nMax<n );
    cout.precision(17);
    double Y[nMax] = { 2.0 , 8.0 };
    for(int k=3; k<=n; ++k)
        Y[k-1] = k + Y[k-1 - 1]/(k-1) + Y[k-1 - 2]/(k-2);
    // k-1 е индекса на k-я елемент
    cout<<"Y( "<<n<<" ) = "<< Y[n-1] <<endl;
    double Last = 8.0, pred = 2.0;
    int indLast = 2;
    while( indLast < n ) {
        double L = Last;
        ++indLast;
        Last = indLast + Last/(indLast-1) + pred/(indLast-2);
        pred = L;
    }

    cout<<"Y( "<<n<<" ) = "<< (1==n ? pred : Last) <<endl;
    cout<<"Y( "<<n<<" ) = "<< upY(n, 2, 8.0, 2.0) <<endl;
    downY(n, Last, pred);
    cout<<"Y( "<<n<<" ) = "<< Last <<endl;
}
