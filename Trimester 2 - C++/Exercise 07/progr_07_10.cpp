#include <iostream>
#include <cstring> // за функции за работа с низове от тип char*
#include <string> // за функции за работа с низове от тип string
using namespace std;

int main() {
    // работа с низове от тип char*
    // тук се налага постоянен контрол на размера на наличната памет

    const int maxStrLen = 200; // максимална дължина на низ
    char sCh1[maxStrLen + 1], sCh2[maxStrLen + 1];
    // + 1 байт за признака за край на низ
    cout << "1-и низ: ";
    cin.getline(sCh1, maxStrLen + 1);
    // maxStrLen+1 укзава, колко е разрешената памет за запис
    // cin.getline по подразбиране чете всико до знака '\n' (Enter)
    // cin>> чете само до разделител (т. е. до ' ', '\t' или '\n')
    cout << "2-и низ: ";
    cin.getline(sCh2, maxStrLen + 2);
    cout << "Низове: \"" << sCh1 << "\" ";
    int rel = strcmp(sCh1, sCh2);
    // strcmp(sCh1, sCh2) връща цяло число,
    // резултат от лексикографкото сравняване на sCh1 и sCh2:
    // положително при sCh1 > sCh2;
    // нула при sCh1 == sCh2;
    // отрицателно при sCh1 < sCh2.
    if (rel > 0) cout << '>';
    else if (rel < 0) cout << '<';
    else cout << '=';
    cout << " \"" << sCh2 << "\"\n";
    int Len1 = strlen(sCh1), Len2 = strlen(sCh2);
    cout << "Дължини: " << Len1 << ' ';
    if (Len1 > Len2) cout << '>';
    else if (Len1 < Len2) cout << '<';
    else cout << '=';
    cout << ' ' << Len2 << "\n\n";

    // работа с низове от тип string
    // тук НЯМА нужда от контрол на размера на наличната памет
    // (той се извършва автоматично при използването на тип string)

    string str1, str2;
    cout << "1-и низ: ";
    getline(cin,str1);
    // getline(cin,str1) по подразбиране чете всико до знак '\n' (Enter)
    // cin>>str1 чете само до разделител (т. е. до ' ', '\t' или '\n')
    cout << "2-и низ: ";
    getline(cin,str2);
    cout << "Низове: \"" << str1 << "\" ";
    rel = str1.compare(str2);
    // str1.compare(str2) също връща цяло число,
    // резултат от лексикографкото сравняване на str1 и str2:
    // положително при str1 > str2;
    // нула при str1 == str2;
    // отрицателно при str1 < str2.
    if (rel > 0) cout << '>';
    else if (rel < 0) cout << '<';
    else cout << '=';
    cout << " \"" << sCh2 << "\"\n";
    // за низове от типа string е позволено сравняване с оператор
    cout << "Низове: \"" << str1 << "\" ";
    if (str1 > str2) cout << '>';
    else if (str1 < str2) cout << '<';
    else cout << '=';
    cout << " \"" << str2 << "\"\n";
    Len1 = str1.length();
    Len2 = str2.length();
    cout << "Дължини: " << Len1 << ' ';
    if (Len1 > Len2) cout << '>';
    else if (Len1 < Len2) cout << '<';
    else cout << '=';
    cout << ' ' << Len2 << "\n\n";
}