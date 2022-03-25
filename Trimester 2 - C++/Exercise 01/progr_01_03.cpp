#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int k, n;
    do {
        cout << "Цяло k от 0 до 3: ";
        cin >> k;
    } while(k<0 || 3<k);

    do {
        cout << "Цяло n от " << k+1 << " до 9: ";
        cin >> n;
    } while(n<k+1 || 9<n);

    for(int w1=1, w2=k+1, w3=n=1;
        w3>0;
        --w3 , w2>1 ? ++w1, --w2 : 0 )
        cout << setfill(' ') << setw(w1) << '='
             << setfill('*') << setw(w2) << '*'
             << setfill(',') << setw(w3) << '&' << endl;
}