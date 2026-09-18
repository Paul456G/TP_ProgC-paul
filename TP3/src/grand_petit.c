#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int plus_grand, plus_petit;

    // Initialisation de la graine pour les nombres aléatoires
    srand(time(NULL));

    // 1. Remplissage du tableau avec 100 valeurs aléatoires entre 1 et 1000
    for (int i = 0; i < 100; i++) {
        tableau[i] = rand() % 1000 + 1;
    }

    // 2. Initialisation des comparateurs avec le premier élément
    plus_grand = tableau[0];
    plus_petit = tableau[0];

    // 3. Parcours du tableau (on commence à l'index 1 puisqu'on a déjà pris l'index 0)
    for (int i = 1; i < 100; i++) {
        if (tableau[i] > plus_grand) {
            plus_grand = tableau[i];
        }
        if (tableau[i] < plus_petit) {
            plus_petit = tableau[i];
        }
    }

    // 4. Affichage des résultats
    printf("Le numero le plus grand est : %d\n", plus_grand);
    printf("Le numero le plus petit est : %d\n", plus_petit);

    return 0;
}