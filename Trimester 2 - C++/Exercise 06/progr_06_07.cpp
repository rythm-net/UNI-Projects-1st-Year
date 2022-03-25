#include <iostream>
using namespace std;
double f(double x);

double g(double x) {
    if( 1.0 <= x && x <= 100.0 )
        return (x + f(x-100.0)) / f(x-200.0);
    return f(x-4.5) - x;
}

int main() {
    double x;
    do {
        cout<<"Число x до 10^40: ";
        cin>>x;
    } while( x>1e40 );
    cout<<"f( "<<x<<" ) = "<<f(x)<<endl
        <<"g( "<<x<<" ) = "<<g(x)<<endl;
}

double f(double x) {
    if( x < -1.0 ) return x - x/10.0;
    return g(x/30.1) + g(x/55.0);
}