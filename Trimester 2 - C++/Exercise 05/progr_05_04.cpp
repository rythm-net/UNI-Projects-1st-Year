#include <iostream>
#include <cstdarg>
using namespace std;

double sum1(int n ...) { // може и така: double sum1(int n, ...)
    va_list L, L2; // за обхождане на формалните параметри
    va_start(L,n); // чрез L може да се обхождат праметрите след n
    va_copy(L2,L); // L2 запомня моментното състояние на L
    double sum=0.0;
    for(int i=1; i<=n; ++i)
        sum += va_arg(L,double); // дава поредния формален параметър
    // като го интерпретира от double
    cout<<"Сума: ";
    for(int i=1; i<=n; ++i)
        if( 1==i ) cout<<va_arg(L2,double);
        else cout<<" + "<<va_arg(L2,double);
    cout<< " = " << sum << endl;
    va_end(L);
    va_end(L2);
    return sum;
}

double sum2(int n ...) {
    double * u = (double *)((int)&n + sizeof(int)), * u2 = u;
    double sum=0.0;
    for(int i=1; i<=n; ++i, ++u) sum += *u;
    cout<<"Сума: ";

    for(int i=1; i<=n; ++i, ++u2)
        if( 1==i ) cout<<*u2;
        else cout<<" + "<<*u2;
    cout<< " = " << sum << endl;
    return sum;
}

int main() {
    double s = sum1(2 , 5.1 , 3.2);

    // типът на фактическите параметри след 1-я трябва буквално
    // да съвпада с типа на формалните параметри, защото
    // преобразуване на тип не се прави за неопределен брой параметри

    cout<<"  s = "<<s<<"\n\n";
    s = sum2(2 , 5.1 , 3.2);
    cout<<"  s = "<<s<<"\n\n";
    s = sum1(4 , 5.1 , 3.2 , 100.0 , 2000.0);
    cout<<"  s = "<<s<<"\n\n";
    s = sum2(4 , 5.1 , 3.2 , 100.0 , 2000.0);
    cout<<"  s = "<<s<<"\n\n";
    cout<<"sum1( 2 , 0.0 , 1.5 ) = "<<sum1(2 , 0.0 , 1.5)<<"\n\n";
    cout<<"sum2( 2 , 0.0 , 1.5 ) = "<<sum2(2 , 0.0 , 1.5)<<endl;
}