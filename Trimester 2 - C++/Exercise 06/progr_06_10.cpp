#include <iostream>
using namespace std;

void upF(int n, int indLast,
         unsigned long long Last,
         unsigned long long pred) {
    if( n < indLast ) return;
    cout<<Last<<", ";
    upF(n, 1+indLast, Last+pred, Last);
}

void downF(int n, unsigned long long & Last,
           unsigned long long & pred) {
    if( 1 == n ) { Last=1uLL; pred=0uLL; }
    else {
        unsigned long long predPred;
        downF(n-1, pred, predPred);
        Last = pred + predPred;
    }
    cout << Last <<", ";
}

int main() {
    int n;
    do {
        cout<<"Индекс от 1 до 93: ";
        cin>>n;
    } while( n<1 || 93<n );

    unsigned long long F[93] = { 1uLL , 1uLL };
    for(int i=2; i<n; ++i) F[i] = F[i-1] + F[i-2];
    for(int i=0; i<n; ++i) cout << F[i] <<", ";
    cout<<endl;

    unsigned long long Last = 1uLL, pred = 0uLL;
    int indLast = 1;
    while( indLast < n ) {
        cout<<Last<<", ";
        unsigned long long L = Last;
        Last = Last+pred;
        pred = L;
        ++indLast;
    }

    cout<< Last <<endl;
    upF(n, 1, 1uLL, 0uLL);
    cout<<endl;
    downF(n, Last, pred);
    cout<<endl;
}