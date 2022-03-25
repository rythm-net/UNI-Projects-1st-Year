#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {

    char sCh[] = "abcd#%=";
    cout << "sCh  -->>  \"" << sCh << "\"\n";
    // strspn(s1,s2) връща максималната дължина на началото на s1,
    // което съдържа само знакове от s2
    cout << "strspn(sCh,\"abcdefgh\")  -->>  "
         << strspn(sCh, "abcdefgh") << endl;
    // strcspn(s1,s2) връща максималната дължина на началото на s1,
    // което съдържа само знакове, отсъствуващи в s2
    cout << "strcspn(sCh,\"cd\")  -->>  "
         << strcspn(sCh, "cd") << endl;
    cout << "strcspn(sCh,\"123%=ZWF\")  -->>  "
         << strcspn(sCh, "123%=ZWF") << endl;
    cout << "* (sCh + strcspn(sCh,\"123%=ZWF\"))  -->>  "
         <<  * (sCh + strcspn(sCh, "123%=ZWF" )) << endl;
    // strpbrk(s1,s2) връща указател към 1-я знак в s1,
    // който се съдържа в s2, или NULL, когато няма такъв знак
    cout << "* strpbrk(sCh,\"123%=ZWF\")  -->>  "
         <<  * strpbrk(sCh, "123%=ZWF" ) << endl;
    cout << "strpbrk(sCh,\"123%=ZWF\") - sCh  -->>  "
         <<  strpbrk(sCh, "123%=ZWF" ) - sCh << "\n\n";

    string str = "abcd#%=";
    cout << "str  -->>  \"" << str << "\"\n";
    cout << "str.find_first_not_of(\"abcdefgh\")  -->>  "
         <<  str.find_first_not_of( "abcdefgh" ) << endl;
    cout << "str.find_first_of(\"cd\")  -->>  "
         <<  str.find_first_of( "cd" ) << endl;
    cout << "str.find_first_of(\"123%=ZWF\")  -->>  "
         <<  str.find_first_of( "123%=ZWF" ) << endl;
    cout << "str[str.find_first_of(\"123%=ZWF\")]  -->>  "
         <<  str[str.find_first_of( "123%=ZWF" )] << endl;
    cout
            <<"* (str.c_str() + str.find_first_of(\"123%=ZWF\"))  -->>  "
            << * (str.c_str() + str.find_first_of( "123%=ZWF" ))
            <<"\n\n";
}