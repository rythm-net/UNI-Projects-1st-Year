#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
    srand(time(NULL));
    cout << rand()%11 - 5 <<"  " <<rand()%11 - 5 << endl;
}