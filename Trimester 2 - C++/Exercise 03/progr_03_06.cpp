#include <iostream>
#include <cmath>
using namespace std;

int const Len = 7;
int main() {
    long double ar[Len];
    for(int i=0; i<Len; ++i) {
        cout<<"  "<< i + 1 <<"-о число (от общо "<<Len<<"): ";
        cin>>ar[i];
    }

    cout<<"Двойки съседни с целочислена сума:\n";
    for(int i=Len-1; 0<i; --i)
        if( trunc(ar[i-1]+ar[i]) == ar[i-1]+ar[i] )
            cout << ar[i - 1] << " + " << ar[i]
                 << " = ar[" << i - 1
                 << "] + ar[" << i << "] = "
                 << ar[i-1] + ar[i] << endl;
    cout<<"(край на двойките)\n";
}