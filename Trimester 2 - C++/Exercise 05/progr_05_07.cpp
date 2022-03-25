#include <iostream>
#include <cstdarg>
using namespace std;

// 1-и начин (СЪС използване на <cstdarg>)
long double average1(int n ...) {
  if( n < 1 ) return 0.0L;
  va_list L;
  va_start(L,n);
  long double sum = 0.0L;
  for(int i=1; i<=n; ++i) sum += va_arg(L,long double);
  va_end(L);
  return sum/n;
}

// 2-и начин (БЕЗ използване на <cstdarg>)
long double average2(int n ...) {
  if( n < 1 ) return 0.0L;
  long double sum = 0.0L, * arg;
  arg = (long double *)( (int)&n + sizeof(n) );//насочване след n
  for(int i=1; i<=n; ++i, ++arg) sum += *arg;
  return sum/n;
}

int main() {
  int const Len = 6;
  long double ar[Len]; // типът трябва да бъде, като във va_arg
  cout<<"Въведете "<<Len<<" реални числа:\n";

  for(int i=0; i<Len; ++i) {
    cout<<"  "<<i+1<<"-о число: ";
    cin>>ar[i];
  }

  cout<<"Средни аритметични:\n";
  for(int num=1; num<=Len; ++num) {
    cout << "( " << ar[0];
    for(int i=1; i<num; ++i) cout << " + " << ar[i];
    cout << " ) / " << num << "    ~  "
         << average1(num,ar[0],ar[1],ar[2],ar[3],ar[4],ar[5])
         << "  =  "
         << average2(num,ar[0],ar[1],ar[2],ar[3],ar[4],ar[5])
         << endl;
  // допустимо е num да бъде по-малко от броя на следващите числа
  }
}