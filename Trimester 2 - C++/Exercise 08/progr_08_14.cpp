#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int Len = 100;
    char s1[1 + Len] = "ij=^89-%,;[]",
            s2[1 + Len] = "ij=^89-%,;[]",
            s3[1 + Len] = "ij=^89-%,;[]",
            s4[1 + Len] =   "=^89-%,;[]",
            cS[1 + Len] = "ij=^89-%,;[]";

    // целта е да се копира поднизът "=^89-%,;[]" върху "89-%,;[]"

    cout<<"   а)\n";
    cout << "s1  -->>  \"" << s1 << "\"\n";
    cout << "s4  -->>    \"" << s4 << "\"\n";
    strcpy(s1 + 4, s4);
    cout << "---- след strcpy(s1 + 5, s4)\n";
    cout << "s1  -->>  \"" << s1 << "\"\n";

    cout<<"\n   б)\n";
    cout << "s2  -->>  \"" << s2 << "\"\n";
    strcpy(s2 + 4, s2 + 2);
    cout << "---- след strcpy(s2 + 4, s2 + 2)\n";
    cout << "s2  -->>  \"" << s2 << "\"\n";

    cout<<"\n   в)\n";
    cout << "s3  -->>  \"" << s2 << "\"\n";
    for(size_t i=strlen(s3)+2; i>=4; --i) s3[i]=s3[i-2];
    cout << "---- след for(size_t i=strlen(s3)+2; i>=4; --i)"
            " s3[i]=s3[i-2]\n";
    cout << "s3  -->>  \"" << s3 << "\"\n";
    cout << "strcmp(s1,s3)  -->>  " << strcmp(s1,s3) << "\n";

    strcpy(s1,cS);
    strcpy(s2,cS);
    strcpy(s3,cS);

    cout<<"\n   г)\n";
    cout << "s1  -->>  \"" << s1 << "\"\n";
    cout << "s4  -->>    \"" << s4 << "\"\n";
    strcpy_s(s1 + 4, Len - 4, s4);
    cout << "---- след strcpy_s(s1 + 4, Len - 4, s4)\n";
    cout << "s1  -->>  \"" << s1 << "\"\n";

    cout<<"\n   д)\n";
    cout << "s2  -->>  \"" << s2 << "\"\n";
    strcpy_s(s2 + 4, Len - 4, s2 + 2);
    cout << "---- след strcpy_s(s2 + 4, Len - 4, s2 + 2)\n";
    cout << "s2  -->>  \"" << s2 << "\"\n";

    char s5[1 + Len] = "8.*=^-;[]",
            s6[1 + Len] = "8.*=^-;[]";

    // следва цел да се копира низът "^-;[]" върху "*=^-;[]"
    // и да се получи низ "8.^-;[]"

    cout<<"\n   е)\n";
    cout << "s5  -->>  \"" << s5 << "\"\n";
    strcpy(s5 + 2, s5 + 4);
    cout << "---- след strcpy(s5 + 2, s5 + 4)\n";
    cout << "s5  -->>  \"" << s5 << "\"\n";

    cout<<"\n   ж)\n";
    cout << "s6  -->>  \"" << s6 << "\"\n";
    strcpy_s(s6 + 2, Len - 2, s6 + 4);
    cout << "---- след strcpy_s(s6 + 2, Len - 2, s6 + 4)\n";
    cout << "s6  -->>  \"" << s6 << "\"\n";

    char s7[1 + Len] = "#.*=^-;[]",
            s8[1 + Len] = "#.*=^-;[]",
            s9[1 + Len] = "#.*=^-;[]";

    // следва цел да се копират 2 знака от поднза ";["
    // върху "*=^-;[]" и да се получи низ "8.;[-;[]"

    cout<<"\n   з)\n";
    cout << "s7  -->>  \"" << s7 << "\"\n";
    strncpy(s7 + 2, s7 + 6, 2);
    cout << "---- след strncpy(s7 + 2, s7 + 6, 2)\n";
    cout << "s7  -->>  \"" << s7 << "\"\n";

    cout<<"\n   и)\n";
    cout << "s8  -->>  \"" << s8 << "\"\n";
    strncpy_s(s8 + 2, Len - 2, s8 + 6, 2);
    cout << "---- след strncpy_s(s8 + 2, Len - 2, s8 + 6, 2)\n";
    cout << "s8  -->>  \"" << s8 << "\"\n";

    cout<<"\n   й)\n";
    cout << "s9  -->>  \"" << s9 << "\"\n";
    for(size_t i=2, n=1; n<=2; ++i, ++n) s9[i]=s9[i+4];
    cout << "---- след for(size_t i=2, n=1; n<=2; ++i, ++n) "
            "s9[i]=s9[i+4];\n";
    cout << "s9  -->>  \"" << s9 << "\"\n";
    cout << "strcmp(s7,s9)  -->>  " << strcmp(s7,s9) << "\n";
}