#include <iostream>
using namespace std;

int const Len = 7;
int main() {
    long double ar[Len];
    for(long double r : ar){
        cout<<"  "<< n++ << "-о число (от общо" << Len << "): ";
        cin>>r;
    }

    cout<<"Двойки съседни с целочислени елементи:\n";
    for(int i=Len-1; 0<i; --i)
        if(trunc(ar[i-1]+ar[i]) == ar[i-1]+ar[i])
            cout<<"числа "<<ar[i-1]<< " и "<<ar[i]
                <<"; индекси "<<i-1<< " и "<< i <<endl;
    cout << " (край на двойките)\n";
}