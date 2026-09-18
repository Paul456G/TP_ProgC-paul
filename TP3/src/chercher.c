#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int cible;
    int trouve = 0; // 0 pour faux, 1 pour vrai

    srand(time(NULL));

    // 1. Remplissage et affichage du tableau (valeurs entre -100 et 100)
    printf("Tableau :\n");
    for (int i = 0; i < 100; i++) {
        tableau[i] = (rand() % 201) - 100;
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 2. Interaction avec l'utilisateur
    printf("Entrez l'entier que vous souhaitez chercher : ");
    // Note : scanf nécessite l'adresse de la variable (d'où le &)
    scanf("%d", &cible);

    // 3. Logique de recherche (recherche linéaire)
    for (int i = 0; i < 100; i++) {
        if (tableau[i] == cible) {
            trouve = 1; // On a trouvé l'entier !
            break;      // On casse la boucle, inutile de lire la suite du tableau
        }
    }

    // 4. Affichage du résultat selon le format demandé
    printf("\nResultat : ");
    if (trouve == 1) {
        printf("entier present\n");
    } else {
        printf("entier absent\n");
    }

    return 0;
}