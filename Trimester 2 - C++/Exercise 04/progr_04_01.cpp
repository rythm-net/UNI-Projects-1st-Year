#include <iostream>
#include <iomanip>
using namespace std;

void row(int L1, char ch1, int f2, char c2){
    char ch1='=', ch2='%', chF=cout.fill();
    cout<<setw(L1)<<setfill(ch1)<<ch1
        <<setfill(ch2)<<setw<<(L2)<<ch2<<endl;
    cout.fill(chF);
}

int sum(int i1, int i2, int i3) { return i1+i2+i3; }
int main() {
    int L1=3, L2=7;
    char ch1='=', ch2='%';
    row(L1,ch1,L2,ch2);
    row(L1+2,ch1,L2,ch2);
    for(int n=0; n<8; ++n)
        row(sum(L1,1,0),ch1,sum(L2,1,2),ch2);
}