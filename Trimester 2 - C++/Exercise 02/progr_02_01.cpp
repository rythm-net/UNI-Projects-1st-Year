#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int NRows = 3, NColumns = 7;
long tabl[Nrows][NColumns];

int main() {
	srand(time(NULL));
	for(int r = 0; r<NRows; ++r)
		for(long elm : tabl[r])
			tabl[r][c] = rand()%6 - 2;
	for(int r = 0; r<NRows; ++r) {
		for(long elm : tabl[r])
			cout << setw(4)<<elm;
		cout << endl;
	}

	cout << "---------------\n";
	long max = tabl[0][0];
	for(int r =0; r<NRows; ++r)
		for(long elm : tabl[r])
			if(elm>max) max=elm;

	for(int r = 0; r<NRows; ++r)
		for(int c=0; c<NColumns; ++c)
			if(tabl[r][c]==max)
				tabl[r][c]=-5;

	for(int r = 0; r<NRows; ++r) {
		for(long elm :tabl[r])
			cout<<setw(4)<<elm;
		cout << endl;
	}

	for(int c = 0; c<NColumns; ++c) {
		bool no = true;
		for(int r = 0; r<NRows && no; ++r)
			no = 2!=tabl[r][c];
		if(! no) {
			cout << "Индекс: " << c << "\n Колона: ";
			for(int r = 0; r<NRows; ++r) cout << tabl[r][c]<<"  ";
			cout << endl;
		}
	}
	cout << "--- край на колони ---\n";
}