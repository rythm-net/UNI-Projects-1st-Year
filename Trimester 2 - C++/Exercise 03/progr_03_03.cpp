#include <iostream>
#include <ctime>
using namespace std;

const int Len = 15;
int main() {
    srand(time(NULL));
    long ar[Len];
    for(long & ref : ar) ref = rand()%6 + 5;
    for(int i=0; i<Len; ++i) {
        int f=0;
        while(f<Len && ar[f] != ar[i]) ++f;
        if(f<i) continue;
        int num = 1;
        for(int j=Len-1; i<j; --j)
            if(ar[i] == ar[j])
                ++num;
        cout << ar[i] << " се среща на "<< num << " места\n";
    }

    cout<<"\n Масив: ";
    for(auto elm : ar) cout<< elm << "  ";
    cout<<"\n\n";
    bool out[Len] = {false};
    for(int i=0; i<Len; ++i)
        if(!out[i]) {
            int num = 1;
            for(int j=Len-1; i<j; --j)
                if(ar[i] == ar[j])
                    ++num;
            out[j] = true;
        }
    cout << ar[i] << " се среща на "<< num << " места\n";
}