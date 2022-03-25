#include <iostream>
using namespace std;

void sum(long s1=0, long s2=0, long s3=0, long s4=0, long s5=0) {
    cout<<s1<<'+'<<s2<<'+'<<s3<<'+'<<s4<<'+'<<s5<<'='
        << s1+s2+s3+s4+s5 <<endl;
}

int main() {
    sum(1,2,3,4,5);
    sum(1,2,3,4);
    sum(1,2,3);
    sum(1,2);
    sum(1);
    sum();
}