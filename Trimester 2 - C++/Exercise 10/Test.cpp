#include <iostream>
using namespace std;
static struct TS { string str; double d; };

int main() {
    TS ts[4];
    for (int i = 0; i < 4; i++) {
        ts[i].d = 1;
        ts[i].str = "aa";
    }
    SumOfStrings(ts);
    return 0;
}

static int SumOfStrings(TS ts[]) {
    for (int i = 0; i < sizeof(ts) / sizeof(*ts); i++) {
        string sum;
        if (ts[i].d > 0) {

            string str = ts[i].str;
            bool diff = true;
            if (diff == true) {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        if (j != k) {

                            if (str[j] == str[k])
                            {
                                break;
                                diff = false;
                            }
                        }
                    }
                }
            }
            if (diff == true) {
                sum += str;
            }
        }
        return sum.length();
    }
}