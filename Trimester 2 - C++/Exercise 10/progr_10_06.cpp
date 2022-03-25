#include <iostream>
using namespace std;

struct TNamedInt {
    string name;
    int value;
    bool operator==(const TNamedInt & s) {
        // това е метод на структурата (функция, част от структурата)
        return name == s.name && value == s.value;
    }
};

void writeNamedInteger(const TNamedInt & ns) {
    cout << "Число: " << ns.name << " = " << ns.value << endl;
}

TNamedInt operator+(const TNamedInt & ns1, const TNamedInt & ns2) {
    // това е функция, която не е част от структурата (не е метод)
    TNamedInt res = ns1;
    res.name += ns2.name;
    res.value += ns2.value;
    return res;
}

ostream & operator<<(ostream & out, TNamedInt & ns) {
    writeNamedInteger(ns);
    return out;
}

int main() {
    TNamedInt n1 = { "x", 100 }, n2 = { "y", 23 }, sum = n1 + n2;
    writeNamedInteger(n1);
    writeNamedInteger(n2);
    writeNamedInteger(sum);
    cout << endl << n1 << n2 << sum << endl;
    cout << boolalpha;
    cout << "n1==n2 <--> " << (n1 == n2) << endl;
    cout << "n2==n2 <--> " << (n2 == n2) << endl;
}