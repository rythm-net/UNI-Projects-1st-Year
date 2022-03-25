#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int NRows = 3, NColumns = 5;
int main() {
    srand(time(NULL));
    long tabl[NRows][NColumns];
    long * ar = tabl[0];
    for(int i=0; i<NRows*NColumns; ++i)
        ar[i] = rand()%6 - 2;

    for(int r=0; r<NRows; ++r) {
        for(long elm : tabl[r])
            cout<<setw(6)<<elm;
        cout<<endl;
    }

    long max=tabl[0][0];
    for(int i=NRows*NColumns-1; 0<=i; --i)
        if(max<ar[i]) max=ar[i];
    for(int r=0; r<NRows; ++r)
        for(int c=0; c<NColumns; ++c)
            if(max==tabl[r][c]) tabl[r][c]=-5;
    cout<<"----------------\n";
    for(int r=0; r<NRows; ++r) {
        for(long elm : tabl[r])
            cout<<setw(6)<<elm;
        cout<<endl;
    }

    cout<<"\n--- Колони, съдържащи 2 ---\n";
    for(int c=0; c<NColumns; ++c) {
        bool no = true;
        for(int r=0; r<NRows && no; ++r)
            no = 2!=tabl[r][c];
        if(! no) { // следва извеждане
            cout<<"Индекс: "<<c<<"\n  Колона: ";
            for(int r=0; r<NRows; ++r) cout<<tabl[r][c]<<"  ";
            cout<<endl;
        }
    }
    cout<<"--- край на колоните ---\n";
}