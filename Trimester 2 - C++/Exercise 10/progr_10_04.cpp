#include <iostream>
using namespace std;

auto f1 = [](int x, int y) {return x+y;};

int main() {

    cout << "f1(3,4) = " << f1(3, 4) << "\n\n";

    typedef int (*TF)(int, int);
    TF f2 = [](int x, int y) {return x*y;};
    cout << "f2(3,4) = " << f2(3, 4) << "\n\n";

    int z = 10;
    auto fz = [&z]() {z*=10;};
    cout << "z = " << z << endl;
    fz();
    cout << "z = " << z << "\n\n";

    auto f3 = [z](int x, int y) {return x+y+z;};
    cout << "f3(3,4) = " << f3(3, 4) << endl;
    fz();
    cout << "z = " << z << endl;
    cout << "f3(3,4) = " << f3(3, 4) << "\n\n";

    auto f4 = [&z](int x, int y) {return x+y+z;};
    cout << "f4(3,4) = " << f4(3, 4) << endl;
    fz();
    cout << "z = " << z << endl;
    cout << "f4(3,4) = " << f4(3, 4) << "\n\n";

    int num = 1;
    cout << "num = " << num << endl;
    auto f5 = [num=40](int x, int y)
    { cout << "num = " << num << endl;
        return x+y+num;
    };
    cout << "f5(3,4) = " << f5(3, 4) << endl;
}