#include <stdio.h>

// Définition de la fonction récursive
int factorielle(int num) {
    if (num == 0 || num == 1) {
        printf("fact(%d): 1\n", num);
        return 1;
    } else {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return valeur;
    }
}

int main() {
    int n = 5;
    
    printf("Test de la fonction factorielle avec n = %d :\n", n);
    int resultat = factorielle(n);
    
    printf("\nResultat final : %d! = %d\n", n, resultat);

    return 0;
}