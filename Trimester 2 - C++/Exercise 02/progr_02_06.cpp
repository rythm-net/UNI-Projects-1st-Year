#include <iostream>
using namespace std;

int main() {
    double f =-1234.23456, h = 1.e200;
    for(int i=0; i<2; ++i){
        double * u;
        if(i) u = &f;
        else u = &h;
        double & ref = *u;
        cout << "ref = " << ref << endl;
    }

    int ar[] = {1,2,3,4,5,6,7};
    for(int elm : ar) cout << elm << "  ";
    cout << endl;
    for(int & elm : ar) elm += 20;
    for(int elm : ar) cout << elm << "  ";
    cout << endl;
}