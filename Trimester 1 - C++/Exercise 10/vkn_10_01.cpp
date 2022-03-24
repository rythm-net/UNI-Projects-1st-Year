//Да се напише програма, която в масив от дробни числа A въвежда k на брой елементи,
// като k e между 2 и 25. k се въвежда от потребителя.
//Програмата да намира максималното число в масива,
// както и позициите в масива, където се среща това число и да ги отпечата на екрана.
//Да се създаде масив B с максимум 25 елемента в него и в него да се въведат всички числа от A,
// които са положителни и са по-малки от 23. Да се отпечатат числата в B.

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    float A[25];
    int k;
    cout << "Vyvedete razmer na masiva A" << endl;
    cin >> k;

    if(cin.fail() || k<2 || k>25) {
        cout << "Wrong input" << endl;
        return 1;
    }

    for(int i=0; i<k; i++) {
        cout << "Vyvedete A[" << i << "]= "<< endl;
        cin >> A[i];
    }

    float max_num=A[0];
    for(int i=1; i<k; i++) {
        if(A[i]>max_num) {
            max_num=A[i];
        }
    }

    cout << "Max num: " << max_num << endl;
    for(int i=0; i<k; i++) {
        if(A[i] == max_num) {
            cout << "Max num pos: " << i << endl;
        }
    }

    vector<float> B;
    for(int i=0; i<k; i++) {
        if(A[i]>0 && A[i]<23) {
            B.push_back(A[i]);
        }
    }

    cout << "Elements in B: " << endl;
    for(float b: B) {
        cout << b << endl;
    }
    return 0;
}