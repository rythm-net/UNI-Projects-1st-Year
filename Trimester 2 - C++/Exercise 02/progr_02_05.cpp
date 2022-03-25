#include <iostream>
using namespace std;

int main(){
    int i=-2, j=78;
    int &r = i;
    cout << "i = " << i << " ; r = " << r << " ; j = " << j << endl;
    r=1;
    j--5;
    cout << "i = " << i << " ; r = " << r << " ; j = " << j << endl;
}