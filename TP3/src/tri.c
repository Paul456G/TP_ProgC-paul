#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int temp;

    // Initialisation de la graine aléatoire
    srand(time(NULL));

    // 1. Remplissage et affichage du tableau non trié
    printf("Tableau non trie :\n");
    for (int i = 0; i < 100; i++) {
        // Nombres aléatoires entre -100 et 100
        tableau[i] = (rand() % 201) - 100;
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 2. Algorithme de tri à bulles
    for (int i = 0; i < 100 - 1; i++) {
        for (int j = 0; j < 100 - i - 1; j++) {
            // Si l'élément actuel est plus grand que le suivant, on les inverse
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    // 3. Affichage du tableau trié par ordre croissant
    printf("Tableau trie par ordre croissant :\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}