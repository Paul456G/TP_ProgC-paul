#include <stdio.h>

int main() {
    int num1 = 42;
    int num2 = 5;
    char op = '|'; // Change cette valeur pour tester les différents cas

    printf("Calcul demande : %d %c %d (sauf pour ~)\n", num1, op, num2);

    switch (op) {
        case '+':
            printf("Resultat : %d\n", num1 + num2);
            break;
        case '-':
            printf("Resultat : %d\n", num1 - num2);
            break;
        case '*':
            printf("Resultat : %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 / num2);
            } else {
                printf("Erreur : Division par zero impossible !\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 % num2);
            } else {
                printf("Erreur : Modulo par zero impossible !\n");
            }
            break;
        case '&':
            printf("Resultat : %d\n", num1 & num2);
            break;
        case '|':
            printf("Resultat : %d\n", num1 | num2);
            break;
        case '~':
            // Le NOT logique (~) s'applique sur un seul opérande
            printf("Resultat (~num1) : %d\n", ~num1);
            break;
        default:
            printf("Erreur : Operateur non reconnu.\n");
            break;
    }

    return 0;
}
