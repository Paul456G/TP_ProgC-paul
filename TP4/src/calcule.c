#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[]) {
    // On s'attend à recevoir 3 arguments : le programme + l'opérateur + num1 + num2
    if (argc != 4) {
        printf("Utilisation : %s <operateur> <num1> <num2>\n", argv[0]);
        printf("Exemple : %s + 15 8\n", argv[0]);
        return 1;
    }

    // Récupération de l'opérateur et conversion des nombres en entiers
    char op = argv[1][0];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    int resultat = 0;
    int operation_valide = 1;

    switch (op) {
        case '+':
            resultat = somme(num1, num2);
            break;
        case '-':
            resultat = difference(num1, num2);
            break;
        case '*':
            resultat = produit(num1, num2);
            break;
        case '/':
            resultat = quotient(num1, num2);
            break;
        case '%':
            resultat = modulo(num1, num2);
            break;
        case '&':
            resultat = et_logique(num1, num2);
            break;
        case '|':
            resultat = ou_logique(num1, num2);
            break;
        case '~':
            resultat = negation(num1);
            break;
        default:
            printf("Operateur non reconnu : %c\n", op);
            operation_valide = 0;
            break;
    }

    if (operation_valide) {
        printf("Resultat : %d\n", resultat);
    }

    return 0;
}