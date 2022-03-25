#include <iostream>
using namespace std;

int main() {
    long long num;
    cout << "Цяло число: ";
    cin >> num;
    int odd = 0, even = 0;

    do {
        if(num%10 %2) ++odd;
        else ++even;
        num /= 10;
    } while(num);
    cout << "Брой на четните цифри: " << even
         <<"\nБрой на нечетните цифри: " << odd << endl;
}