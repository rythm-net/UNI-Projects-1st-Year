#include <iostream>
#include <strstream>
using namespace std;

char strStream[] = "  abc * 1234  ** 78zy";

int main() {
    istrstream strIn(strStream);
    int row = 1;
    string s;
    while( getline(strIn, s, '*') )
        cout << "ред " << row++ << ":  \"" << s << "\"\n";
    cout << "strStream == \"" << strStream << "\"\n";
    ostrstream strOut(strStream, sizeof(strStream));
    for(int i=1; i<=50; ++i)
        if( ! (strOut<<i<<" ") ) break;
    cout << "strStream == \"" << strStream << "\"\n";
}