#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    // трябва да има поне един клон на изпълнението на f,
    // който не предизвиква рекурсивно извикване
    if( x>300.0 ) return x/2.0;
    if( 0.0<=x ) return sqrt(x);
    if( -1200.0<x ) return x*x;
    return f(x/5.0) + f(-sqrt(-x));
}

int main() {
    double x;
    cout<<"Число x: ";
    cin>>x;
    cout<<"f( "<<x<<" ) = "<<f(x)<<endl;
}