#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 11 // Taille basée sur l'exemple du sujet

int main() {
    int tab_int[TAILLE];
    float tab_float[TAILLE];

    // Initialisation de la graine pour l'aléatoire
    srand(time(NULL));

    // 1. Remplissage des tableaux (uniquement avec des pointeurs)
    for (int i = 0; i < TAILLE; i++) {
        *(tab_int + i) = rand() % 100 + 1;                  // Entiers entre 1 et 100
        *(tab_float + i) = (float)(rand() % 1000) / 100.0f; // Flottants entre 0.00 et 9.99
    }

    // 2. Affichage AVANT multiplication
    printf("Tableau d'entiers (avant la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d", *(tab_int + i));
        if (i < TAILLE - 1) printf(", ");
    }
    printf("\n\n");

    printf("Tableau de nombres a virgule flottante (avant la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f", *(tab_float + i));
        if (i < TAILLE - 1) printf(", ");
    }
    printf("\n\n");

    // 3. Multiplication par 3 pour les indices divisibles par 2 (pairs)
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            *(tab_int + i) *= 3;
            *(tab_float + i) *= 3.0f;
        }
    }

    // 4. Affichage APRÈS multiplication
    printf("Tableau d'entiers (apres la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d", *(tab_int + i));
        if (i < TAILLE - 1) printf(", ");
    }
    printf("\n\n");

    printf("Tableau de nombres a virgule flottante (apres la multiplication par 3) :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f", *(tab_float + i));
        if (i < TAILLE - 1) printf(", ");
    }
    printf("\n");

    return 0;
}