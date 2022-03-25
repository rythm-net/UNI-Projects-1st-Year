#include <iostream>
using namespace std;
double g(double x);
// името x на формалния параметър в предварителната декларация
// на g се използва в подсказките, давани от редактора
// на интегрираната среда, но се игнорира при транслацията
double f(double x) {
    if( x <= 100.0 ) return  x*x;
    return 100.0 + f(x/2.0) + g(x-700.0);
}
/*
// може и така:
double f(double x) {
  double g(double x);
  // така функцията g е достъпна в f и НЕ Е достъпна в main
  if( x <= 100.0 ) return  x*x;
  return 100.0 + f(x/2.0) + g(x-700.0);
}
*/
int main() {
    double x;
    do {
        cout<<"Число x до 15000: ";
        cin>>x;
    } while( x>15000.0 );
    cout<<"g( "<<x<<" ) = "<<g(x)<<endl;
}
    double g(double x) {
    if( x <= 200.0 ) return x;
    return 1.0 + f(x) + g(x-500.0);
}