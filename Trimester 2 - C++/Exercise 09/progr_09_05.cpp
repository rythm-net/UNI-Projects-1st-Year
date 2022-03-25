#include <iostream>
#include <string>
using namespace std;

const int number = 4;
const string digitsAndLetters = "0123456789"
                                "abcdefghijklmnopqrstuvwxyz";
struct TwoStrAndNum {
    // за двойка низове и цяло число
    string s1, s2;
    int n;
};

void readStruct(TwoStrAndNum & s) {
    do {
        cout << "    четно число: ";
        cin >> s.n;
    } while (s.n % 2);

    getline(cin, s.s1); // изчиства буфера на клавиатурата

    do {
        cout << "    1-и низ (<цифра><букви и цифри><цифра>): ";
        getline(cin, s.s1);
    } while (    s.s1.length() == 0
                 || digitsAndLetters.find(s.s1.front()) >= 10
                 || digitsAndLetters.find(s.s1.back()) >= 10
                 || string::npos
                    != s.s1.find_first_not_of(digitsAndLetters));

    do {
        cout << "    2-и низ (<цифра><букви и цифри><цифра>): ";
        getline(cin, s.s2);
    } while (    s.s2.length() == 0
                 || digitsAndLetters.find(s.s2.front()) >= 10
                 || digitsAndLetters.find(s.s2.back()) >= 10
                 || string::npos
                    != s.s2.find_first_not_of(digitsAndLetters));
}

void writeStruct(const TwoStrAndNum & s) {
    cout << "  \"" << s.s1 << "\" ; \"" << s.s2 << "\" ; " << s.n
         << endl;
}

void readArray(TwoStrAndNum a[], int L) {
    cout << "Въведете данните за " << L << " стоки:\n";
    for (int i = 0; i < L; ++i) {
        cout << "  за " << i + 1 << "-а стока:\n";
        readStruct(a[i]);
    }
}

void writeArray(const TwoStrAndNum a[], int L) {
    cout << "Масив:\n";
    for (int i = 0; i < L; ++i) writeStruct(a[i]);
    cout << endl;
}

int maxNumber(const TwoStrAndNum a[], int L) {
    int max = a[0].n;
    for (int i = 1; i < L; ++i)
        if (a[i].n > max)
            max = a[i].n;
    return max;
}

void viewStructWithMaxNum(const TwoStrAndNum a[], int L)
{ // към Б.в)
    int max = maxNumber(a, L);
    cout << "Структури с максимално число:\n";
    for (int i = 1; i < L; ++i)
        if (a[i].n == max)
            writeStruct(a[i]);
    cout << endl;
}

double averageFromChar(const TwoStrAndNum a[], int L, char c) {
    int k = 0;
    double sum = 0.0;
    for (int i = 0; i < L; ++i)
        if (    string::npos != a[i].s1.find(c)
                || string::npos != a[i].s2.find(c)
                )
            ++k, sum += a[i].n;
    return k ? sum / k : 1.0 / 0.0;
}

int countElmWithCharIn3Pos(const TwoStrAndNum a[], int L) {
    int k = 0;
    size_t pos1, pos2;
    for(int i = 0; i < L; ++i) {
        for(char c : a[i].s2)
            if(    string::npos != (pos1 = a[i].s1.find(c))
                   && string::npos != (pos2 = a[i].s1.find(c, pos1 + 1))
                   && string::npos != a[i].s1.find(c, pos2 + 2)
                    )
                ++k;
    }
    return k;
}

void viewLastCharDiv(const TwoStrAndNum a[], int L) {
    string LastCh; // по подразбиране се инициализира с ""
    for (int i = 0; i < L; ++i)
        if ( a[i].n % 3 == 0 ) {
            if ( string::npos == LastCh.find(a[i].s1.back()) )
                LastCh.push_back(a[i].s1.back());
            if ( string::npos == LastCh.find(a[i].s2.back()) )
                LastCh.push_back(a[i].s2.back());
        }
    cout << "Цифри в края на низове, "
            "асоциирани с кратно на 3 число:\n";
    for (char c : LastCh)
        cout << "  \'" << c << '\'';
    cout << "\n(край на цифрите)\n\n";
}

int main() {
    TwoStrAndNum ar[number];
    readArray(ar, number);
    writeArray(ar, number);
    viewStructWithMaxNum(ar, number);
    char ch;
    string str;

    do {
        cout << "Знак, срещан в низовете: ";
        getline(cin, str);
    } while (str.length() == 0);

    ch = str[0];
    cout << "Средно аритмтично: "
         << averageFromChar(ar, number, ch) << endl;
    viewLastCharDiv(ar, number);
}