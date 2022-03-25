#include <iostream>
using namespace std;

void move(int k, int start, int end) {
    if( 1 > k ) return;
    int midl = 3 - start - end;
    move(k-1, start, midl);
    cout<<start<<"->"<<end<<", ";
    move(k-1, midl, end);
}

int main() {
    int n;
    do {
        cout<<"Брой до 10: ";
        cin>>n;
    } while( n<1 || 10<n );
    move(n,0,2);
    cout<<endl;
}