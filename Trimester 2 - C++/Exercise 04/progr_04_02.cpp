#include <iostream>
#include <iomanip>
using namespace std;

void row(char c1, int L, char c2, char c3){
    char chF=cout.fill();
    cout<<c1<<setfill(c2)<<setw(L+1)<<c3<<endl;
    cout.fill(chF);
}

int main() {
    int r, c;
    do {
        cout<<"Броеве редове и колони от 2 до 10: ";
        cin>>r>>c;
    } while(r<2 || 10<r || c<2 || 10<c);

    char ch1, ch2, ch3;
    cout<<"Три знака: ";
    cin>>ch1>>ch2>>ch3;
    row(ch1,c-2,ch2,ch3);
    cout<<ch1<<setfill(ch2)<<setw(c-1)<<ch3<<endl;
    for(int n=2; n<r; ++n)
        row(ch1,c-2,' ',ch3);
    row(ch1,c-2,ch2,ch3);
}