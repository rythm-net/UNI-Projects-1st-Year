#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int Len = 10;
    long ar[Len];
    for(long &ref : ar) ref = rand()%21 - 15;
    for(long elm : ar) cout<<elm<<"  ";
    cout<<endl;
    int Last = Len-1;
    while( 0<=Last && ! (ar[Last]%2) ) --Last;

    if(0>Last) cout<<"Няма нечетен елемент.\n";
    else {
        long &refOdd = ar[Last];
        refOdd *= 2;
    }

    cout<<"Резултат:\n";
    for(long elm : ar) cout<<elm<<"  ";
    cout<<endl;
}