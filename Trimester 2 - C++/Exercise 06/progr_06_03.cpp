#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    if (x < 10.0)
        return x + x;
    if (trunc(x) == x)
        return sqrt(x) + f(x / 10.0 - 10.0);
    return x / 2.0 + f(x / 7.0) + f(x / 11.0);
}

int main() {
    double x;
    cout << "Число x: ";
    cin >> x;
    cout << "f( " << x << " ) = " << f(x) << endl;
}