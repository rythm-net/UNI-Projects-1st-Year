#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Цяло число: ";
    cin >> n;
    int even = 0, odd = 0;

    do {
        if ( n%10 % 2 ) ++odd;
        else ++even;
        n /= 10; // n = n/10;
    } while (n);

    cout << "Брой на четните цифри: " << even
         << "\nБрой на нечетните цифри: " << odd << endl;
}