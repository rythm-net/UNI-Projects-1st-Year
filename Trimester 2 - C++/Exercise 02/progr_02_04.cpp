#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    srand(time(NULL));
    const int Len = 15;
    long ar[Len];

    for(int i=0; i<Len; ++i) ar[i] = rand()%4 + 8;
    for(long elm : ar) cout << setw(4)<<elm;
    cout << endl;

    for(int i=0; i<Len; ++i) cout << setw(4)<<i;
    cout << endl;
    long min = ar[0];
    int minCount = 0;

    for(long elm : ar)
        if(elm == min) ++minCount;
        else if(elm < min) { min=elm; minCount=1; }
    int * indx = new int[minCount];

    for(int i=0, pos=0; i<Len; ++i)
        if(min == ar[i])
            indx[pos++] = i;

    cout << "Индекси на минималните елементи: ";
    for(int pos=0; pos<minCount; ++pos) cout << indx[pos] << "  ";
    cout << endl;
    ar[ indx[pos] ] += 100;
    delete[] indx;
    indx = NULL;
    for(long elm : ar) cout << setw(4)<<elm;
    cout << endl;
    for(int i=0; i<Len; ++i) cout << setw(4)<<i;
    cout << endl;
}