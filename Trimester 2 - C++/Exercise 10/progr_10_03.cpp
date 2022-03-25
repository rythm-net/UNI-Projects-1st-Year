#include <iostream>
#include <cstring> // заради strchr
using namespace std;

typedef double (*FPointer)(double arg1, double arg2);
double add(double n1, double n2) {
    return n1 + n2;
}

double sub(double n1, double n2) {
    return n1 - n2;
}

double mult(double n1, double n2) {
    return n1 * n2;
}

double division(double n1, double n2) {
    return n1 / n2;
}

FPointer setF(char op) {
    switch (op) {
        case '+':
            return &add;
        case '-':
            return sub; // може sub вместо &sub
        case '*':
            return mult;
        default:
            return division;
    }
}

double result(double arg1, double arg2, FPointer f) {
    return (*f)(arg1, arg2);
}

int main() {
    double x, y;
    cout << "Две числа: ";
    cin >> x >> y;
    char op;

    do {
        cout << "Знак +, -, * или /: ";
        cin >> op;
    } while (!strchr("+-*/", op));
    cout << x << op << y << " = "
         << result(x, y, setF(op))
         << endl;
}