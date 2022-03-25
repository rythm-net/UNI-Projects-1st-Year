#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int numColumns = 7, // брой на колоните в масива
width = 5; // широчина на колона при извеждането
void setTable(long t[][numColumns], int rows,
              long min, long max) {
    for (int r = rows - 1; 0 <= r; --r)
        for (int c = numColumns - 1; 0 <= c; --c)
            t[r][c] = rand() % (max - min + 1) + min;
}

void writeTable(const long t[][numColumns], int rows) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < numColumns; ++c)
            cout << setw(width) << t[r][c];
        cout << endl;
    }
}

void LastIndicesMaximum(const long t[][numColumns], int rows,
                        int & rIndMax, int & cIndMax) {
    cIndMax = numColumns - 1;
    for (int r = rIndMax = rows - 1; 0 <= r; --r)
        for (int c = numColumns - 1; 0 <= c; --c)
            if (t[r][c] > t[rIndMax][cIndMax]) {
                rIndMax = r;
                cIndMax = c;
            }
}

int main() {
    srand(time(NULL));
    int const numRows = 4; // брой на редовете в масива
    long tabl[numRows][numColumns] ;
    setTable(tabl, numRows, -10, 15);
    writeTable(tabl,numRows);
    int LastR, LastC;
    LastIndicesMaximum(tabl, numRows, LastR, LastC);
    cout << "Индекси на последен максимален: "
         << LastR << " и " << LastC << endl;
}