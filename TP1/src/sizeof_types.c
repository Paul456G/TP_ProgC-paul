#include <stdio.h>

int main() {
    // Types caractères
    printf("char : %zu octets\n", sizeof(char));
    printf("unsigned char : %zu octets\n", sizeof(unsigned char));

    // Types entiers courts
    printf("short : %zu octets\n", sizeof(short));
    printf("unsigned short : %zu octets\n", sizeof(unsigned short));

    // Types entiers standards
    printf("int : %zu octets\n", sizeof(int));
    printf("unsigned int : %zu octets\n", sizeof(unsigned int));

    // Types entiers longs
    printf("long int : %zu octets\n", sizeof(long int));
    printf("unsigned long int : %zu octets\n", sizeof(unsigned long int));

    // Types entiers très longs
    printf("long long int : %zu octets\n", sizeof(long long int));
    printf("unsigned long long int : %zu octets\n", sizeof(unsigned long long int));

    // Types à virgule flottante (ni signed, ni unsigned)
    printf("float : %zu octets\n", sizeof(float));
    printf("double : %zu octets\n", sizeof(double));
    printf("long double : %zu octets\n", sizeof(long double));

    return 0;
}
