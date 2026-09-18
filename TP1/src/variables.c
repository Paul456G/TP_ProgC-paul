#include <stdio.h>

int main() {
    // i. char
    char c = 'A'; // ou un nombre entre -128 et 127
    unsigned char uc = 250;
    printf("char : %c\n", c);
    printf("unsigned char : %hhu\n", uc);

    // ii. short
    short s = -32000;
    unsigned short us = 65000;
    printf("short : %hd\n", s);
    printf("unsigned short : %hu\n", us);

    // iii. int
    int i = -2000000000;
    unsigned int ui = 4000000000U;
    printf("int : %d\n", i);
    printf("unsigned int : %u\n", ui);

    // iv. long int
    long int li = -1000000L;
    unsigned long int uli = 1000000UL;
    printf("long int : %ld\n", li);
    printf("unsigned long int : %lu\n", uli);

    // v. long long int
    long long int lli = -9000000000000000000LL;
    unsigned long long int ulli = 18000000000000000000ULL;
    printf("long long int : %lld\n", lli);
    printf("unsigned long long int : %llu\n", ulli);

    // vi. float
    float f = 3.14159f;
    printf("float : %f\n", f);

    // vii. double
    double d = 3.1415926535;
    printf("double : %lf\n", d);

    // viii. long double
    long double ld = 3.14159265358979323846L;
    printf("long double : %Lf\n", ld);

    return 0;
}