#include <iostream>
using namespace std;

struct TIntChar2 { int i; char c1, c2; };
struct { // анонимен тип на структура
    double d1, d2;
    int h;
}
a1, a2;
decltype(a1) a3 = a2; // деклариране на структура от анонимен тип
typedef decltype(a2) TA; // задаване на име за анонимен тип
TA a4; // използване на име на тип, дефинирано с #typedef
struct TS {
    string str;
    int n1,
            n2 = 99, // 99 ще бъде използвано за инициализиране на n2
    // но само когато няма друга
    // зададен стойност за инициализация
    n3;
}
s1, *p = &s1, s2, &r = s2,
s3 = { "#$%", 11, 22, 33 }, // пълна инициализация на структура
s4 = { "=-=-=", 101 }, // частична инициализация на структура
s5 = { }, // инициализация със стойности по подразбиране
s6 { { }, { }, { }, 6655 },
// първите три полета се инициализира със
// стойностите по подразбиране за типа им
m[8] = { { },
         { "elm2", -2, -3, -4 },
         { "elm3" },
         { { }, 434 } };
// частична инициализация на масив от структури

void writeStruct(const TS & s, const char * message) {
    // извежда съобщение и след него стойността на структурата s
    cout << message << "   str=\"" << s.str << "\" , n1=" << s.n1
         << " , n2=" << s.n2 << " , n3=" << s.n3 << endl;
}

void setFieldN3(TS & s, int i) { s.n3 = i; }
void setFieldN3_pointer(TS * p, int i) { p->n3 = i; }

int main() {
    cout << "Глобални данни:\n";
    writeStruct(s1, "s1:");
    writeStruct(*p, "*p:");
    writeStruct(s2, "s2:");
    writeStruct(r, "r :");
    cout << endl;
    writeStruct(s3, "s3:");
    writeStruct(s4, "s4:");
    writeStruct(s5, "s5:");
    writeStruct(s6, "s6:");
    writeStruct(m[3], "m[3]:");
    cout << endl;
    cout << "s1.n3 = " << s1.n3 << endl;
    cout << "(*p).n3 = " << (*p).n3 << endl;
    cout << "p -> n3 = " << p->n3 << endl;
    cout << "(&s1) -> n3 = " << (&s1)->n3 << endl;

    struct TS s7 = { "****", -5 };
    TS s8, s9; // няма да се извърши инициализация на n1 и n3,
    // защото s8 и s9 са локални и са декларирани без инициализатор
    // str се инициализира с "", защото е от тип string
    // n2 се инициализира с 99, защото е указано за TS

    cout << endl << "Локални данни:\n";
    writeStruct(s7, "s7:");
    writeStruct(s8, "s8:");
    writeStruct(s9, "s9:");

    s6.n3 = -2;
    s7.n3 = -333;
    s8.n3 = -444;
    cout << endl << "Преди промените:\n";
    cout << "s6.n3 = " << s6.n3 << endl;
    cout << "s7.n3 = " << s7.n3 << endl;
    cout << "s8.n3 = " << s8.n3 << endl;

    s8 = s7 = s6;
    cout << endl << "След s8 = s7 = s6:\n";
    cout << "s6.n3 = " << s6.n3 << endl;
    cout << "s7.n3 = " << s7.n3 << endl;
    cout << "s8.n3 = " << s8.n3 << endl;

    setFieldN3(s6, 567);
    cout << endl << "След setFieldN3(s6, 567):\n";
    cout << "s6.n3 = " << s6.n3 << endl;
    cout << "s7.n3 = " << s7.n3 << endl;
    cout << "s8.n3 = " << s8.n3 << endl;

    setFieldN3_pointer(& s8, -9900);
    cout << endl << "След setFieldN3_pointer(& s8, -9900):\n";
    cout << "s6.n3 = " << s6.n3 << endl;
    cout << "s7.n3 = " << s7.n3 << endl;
    cout << "s8.n3 = " << s8.n3 << endl;
}