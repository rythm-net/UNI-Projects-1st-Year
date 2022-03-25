#include <iostream>
using namespace std;

int main() {
	int const number = 6;
	long long ar[number];
	for(int i=0; i<number; ++i){
		cout<<"  "<< i+1 << "-о число (от общо "<<number<<"): ";
		cin>>ar[i];
	}

	for(long long r = -2; r<=2; ++r) {
		cout<<"остатък "<< r <<" се получава от: ";
		for(long long elm : ar)
			if(elm % 3 == r)
				cout<<elm<<' ';
		cout<<endl;
	}
}