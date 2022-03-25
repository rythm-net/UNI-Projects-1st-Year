#include <iostream>
#include <cstdarg>
using namespace std;

void viewMax1(int num ...) { // чрез <cstdarg>
    va_list L;
    va_start(L,num);
    long long max = 0;
    cout<<"max( ";
    for(int i=1; i<=num; ++i) {
        long long arg = va_arg(L,long long);
        if( 1 < i ) cout<<" ; ";
        else max = arg;
        cout<<arg;
        if( max < arg ) max = arg;
    }
    cout<<" ) = "<<max<<endl;
    va_end(L);
}

void viewMax2(int num ...) { // без <cstdarg>
    long long * arg = (long long *)( (int)&num + sizeof(num) );
    long long max = 0;
    cout<<"max( ";
    for(int i=1; i<=num; ++i, ++arg) {
        if( 1 < i ) cout<<" ; ";
        else max = *arg;
        cout<<*arg;
        if( max < *arg ) max = *arg;
    }
    cout<<" ) = "<<max<<endl;
}

int main() {
    long long ar[5];
    cout<<"Въведете 5 цели числа:\n";
    for(int i=0; i<5; ++i) {
        cout<<"   "<<i+1<<"-о число: ";
        cin>>ar[i];
    }

    for(long long elm : ar) cout<<elm<<"   ";
    cout<<endl;

    viewMax1(1,ar[0]);
    viewMax1(2,ar[0],ar[1]);
    viewMax1(3,ar[0],ar[1],ar[2]);

    viewMax2(4,ar[0],ar[1],ar[2],ar[3]);
    viewMax2(5,ar[0],ar[1],ar[2],ar[3],ar[4]);
}