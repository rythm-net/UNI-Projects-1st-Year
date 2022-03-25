#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
    if( 100<x && x<y ) return x+y;
    // В този момент може да бъде, но и да не бъде,
    // нарушено всяко от двете условия 100<x и x<y.
    // Затова следващият if проверява и трите условия.
    if( -10<=x && x<=100 && x<y )
        return sqrt( fabs(x) ) + sqrt( fabs(y) );
    // аналогично следващият if трябва да проверява три условия
    if( -10<=x && x<=100 && x>=y ) return x*x - y*y;
    // тук вече няма нужда от проверки
    return 1 + f( -sqrt(fabs(x)) , -sqrt(fabs(y)) )
           + f( -sqrt(fabs(y)) , -sqrt(fabs(x)) );
}

int main() {
    double x,y;
    cout<<"Числа x y: ";
    cin>>x>>y;
    cout<<"f( "<<x<<" ; "<<y<<" ) = "<< f(x,y) <<endl;
}