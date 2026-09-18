#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    // 1. Addition
    printf("Addition (a + b) = %d\n", a + b);

    // 2. Soustraction
    printf("Soustraction (a - b) = %d\n", a - b);

    // 3. Multiplication
    printf("Multiplication (a * b) = %d\n", a * b);

    // 4. Division
    // Note : Comme a et b sont des entiers, il s'agit d'une division entière.
    printf("Division (a / b) = %d\n", a / b);

    // 5. Modulo (reste de la division)
    printf("Modulo (a %% b) = %d\n", a % b);

    // 6. Égalité (0 = faux, 1 = vrai)
    printf("a est-il egal a b ? (a == b) = %d\n", a == b);

    // 7. Supériorité (0 = faux, 1 = vrai)
    printf("a est-il superieur a b ? (a > b) = %d\n", a > b);

    return 0;
}
