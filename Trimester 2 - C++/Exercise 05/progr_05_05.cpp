#include <iostream>
#include <cstdarg>
using namespace std;

long double sum1(int t ...) { // чрез <cstdarg>
    // стойности на t:
    //   t==0 - няма следващ параметър;
    //   t==1 - следващият параметър е от тип long long
    //   t==2 - следващият параметър е от тип double
    //   t==3 - следващият параметър е от тип long

    va_list L;
    va_start(L,t);
    long double sum=0.0L;
    while(t) {
        switch(t) {
            case 1: sum += va_arg(L,long long); break;
            case 2: sum += va_arg(L,double); break;
            case 3: sum += va_arg(L,long);
        }
        t = va_arg(L,int);
    }
    va_end(L);
    return sum;
}

long double sum2(int t ...) { // без <cstdarg>
    // При достъпа до формалните параматри трябва да се отчитат
    // и форматът на физическото им представяне,
    // и размерът на резервираната за тях памет.
    // Например, дали за цял тип със стойност в под 4 байта
    // се резервират 4 или по-малко байта.
    long double sum=0.0L;
    void * arg; // указател към стойност от неопределен тип
    arg = (void *)( (int)&t + sizeof(t) );//насочва се точно след t
    while(t) {
        switch(t) {
            case 1: // за параметър от тип long long
                sum += *(long long *)arg;
                // интерпретира arg като
                // указател към число от тип long long
                arg = (void *)( (int)arg + sizeof(long long) );
                // насочване на arg след току-що прочетеното
                break;
            case 2: // за параметър от тип double
                sum += *(double *)arg;
                // интерпретира arg като
                // указател към число от тип double
                arg = (void *)( (int)arg + sizeof(double) );
                // насочване на arg след току-що прочетеното
                break;
            case 3: // за параметър от тип long
                sum += *(long *)arg;
                // интерпретира arg като
                // указател към число от тип long
                arg = (void *)( (int)arg + sizeof(long) );
                // насочване на arg след току-що прочетеното
        }
        t = *(int *)arg;
        // интерпретира arg като указател към число от тип int
        arg = (void *)( (int)arg + sizeof(int) );
        // насочване на arg след току-що прочетеното
    }
    return sum;
}

int main() {
    // типът на всеки, освен 1-я, фактически параметър трябва
    // точно да съвпада с типа на съответния му формален параметър
    cout << "  sum1( 3, 2L, 2, 0.5, 1, 23LL, 0 )\n"
         << "2L + 0.5 + 23LL = "
         << sum1( 3, 2L, 2, 0.5, 1, 23LL, 0 )
         << endl;
    cout << "  sum1( 2, 0.5, 1, 23LL, 3, 2L, 0 )\n"
         << "0.5 + 23LL + 2L = "
         << sum1( 2, 0.5, 1, 23LL, 3, 2L, 0 )
         << "\n\n";

    cout << "  sum2( 3, 2L, 2, 0.5, 1, 23LL, 0 )\n"
         << "2L + 0.5 + 23LL = "
         << sum2( 3, 2L, 2, 0.5, 1, 23LL, 0 )
         << endl;
    cout << "  sum2( 2, 0.5, 1, 23LL, 3, 2L, 0 )\n"
         << "0.5 + 23LL + 2L = "
         << sum2( 2, 0.5, 1, 23LL, 3, 2L, 0 )
         << "\n\n";
}