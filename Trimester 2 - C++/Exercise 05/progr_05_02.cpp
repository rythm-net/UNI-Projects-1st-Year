#include <iostream>
using namespace std;

double arOp(double n1=0.0, double n2=1.0, char op='+') {
    switch( op ) {
        default: return n1+n2;
        case '*': return n1*n2;
        case '-': return n1-n2;
        case '/': return n1/n2; //при делене с нула връща безкрайност
    }
}

int main() {
    double x,y;
    cout<<"Два операнда числа: ";
    cin>>x>>y;
    char c;
    cout<<"Знак +, -, * или /: ";
    cin>>c;
    cout<<x<<c<<y<<" = "<< arOp(x,y,c) <<endl;
    cout<<x<<'+'<<y<<" = "<< arOp(x,y) <<endl;
    cout<<x<<'+'<<1<<" = "<< arOp(x) <<endl;
    cout<<0<<'+'<<1<<" = "<< arOp() <<endl;
}