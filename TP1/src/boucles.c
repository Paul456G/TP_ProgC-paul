#include <stdio.h>

int main() {
    int compteur = 5; // Tu peux modifier cette valeur (doit rester < 10)

    printf("=== Version avec boucles FOR ===\n");
    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            // Condition : première colonne, dernière colonne, ou dernière ligne
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n"); // Retour à la ligne après chaque rangée
    }

    printf("\n=== Version avec boucle WHILE et BREAK/CONTINUE ===\n");
    int i = 1;
    while (1) { // Boucle infinie, on sortira de force avec break
        if (i > compteur) {
            break; // Stoppe la boucle quand on dépasse le compteur
        }
        
        int j = 1;
        while (j <= i) {
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
                j++;
                continue; // Passe directement à l'itération suivante du while(j <= i)
            }
            printf("# ");
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}