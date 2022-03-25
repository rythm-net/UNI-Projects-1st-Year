#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    cout << "abc" << endl;
    for (int i = 0; i < 4; ++i)
        cout << i << " -->> \'" << "abc"[i] << "\' (код: "
             << (int) ("abc"[i]) << ")\n";
    cout << "abc\000def" << endl; // литералът съдържа знак с код 0
    // извеждането е допреди първия знак с код 0
    for (int i = 0; i < 8; ++i)
        cout << i << " -->> \'" << "abc\000def"[i] << "\' (код: "
             << (int) ("abc\000def"[i]) << ")\n";
    cout << "\n typeid(\"abc\").name() = " << typeid("abc").name();
    char arCh[] = "abc";
    cout << "\n typeid(arCh).name() = " << typeid(arCh).name();
    const char * pCh = "abc";
    cout << "\n typeid(pCh).name() = " << typeid(pCh).name();
    char * p = (char *) "abc";
    // преобразуване към неконстантен указател
    cout << "\n typeid(p).name() = " << typeid(p).name();
    cout << "\n\n cout<<arCh  --->>  " << arCh;
    cout << "\n cout<<pCh  --->>  " << pCh;
    cout << "\n cout<<p  --->>  " << p << endl;
}