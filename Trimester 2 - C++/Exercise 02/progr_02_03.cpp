#include <iostream>
using namespace std;

int main(){
    double * u;
    int Len=3;
    u = new double[Len] {1,2,3};
    for(int i=0; i<Len; ++i) u[i] = 1.5 + i*10.5;
    for(int i=0; i<Len; ++i) cout << u[i]<<"  ";
    cout << endl;
    delete[] u;
    u = NULL;
}