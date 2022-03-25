#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int Len = 10;
    long ar[Len];
    for(long & ref : ar) ref = rand()%21 - 15;
    for(long elm : ar) cout << elm << '  ';
    cout << endl;
    int Last = Len-1;
    while(0<=Last && ! (ar[Last]) ) --Last;

    if(0>Last) cout << "Няма нечетно число.\n";
    else {
        long & LastOdd = ar[Last];
        cout << "По следен нечетен: " << LastOdd << endl;
        LastOdd *=2;
    }
    for(long elm : ar) cout << elm <<'  ';
    cout << endl;
}