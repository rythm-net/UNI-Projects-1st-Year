#include <iostream>
#include <cmath>
using namespace std;

double F(double x) {
    if (x < 200.0)
        return 100.0 - x;
    //cout<<"-->>"<<trunc(x) - 10.0*trunc(x/10.0)<<endl; // за тест
    if ( trunc(x) - 10.0*trunc(x/10.0) == 2.0 )
        return x * x + F(x / 40.0);
    return x * x - F(sqrt(x)) + F(x / 50.0);
}

int main() {
    double x;
    cout << "Реално число x: ";
    cin >> x;
    cout << "F( " << x << " ) = " << F(x) << endl;
}