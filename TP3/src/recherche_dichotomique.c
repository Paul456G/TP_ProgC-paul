#include <stdio.h>

int main() {
    int tableau[100];
    int cible;
    int debut = 0;
    int fin = 99;
    int milieu;
    int trouve = 0; // 0 pour faux, 1 pour vrai

    // 1. Création et affichage du tableau déjà trié (de -2 à 97)
    printf("Tableau trie :\n");
    for (int i = 0; i < 100; i++) {
        tableau[i] = -2 + i;
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 2. Demande de la valeur à chercher
    printf("Entrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &cible);

    // 3. Algorithme de recherche dichotomique
    while (debut <= fin) {
        milieu = (debut + fin) / 2; // On coupe l'intervalle en deux

        if (tableau[milieu] == cible) {
            trouve = 1; // Valeur trouvée
            break;
        } else if (tableau[milieu] < cible) {
            debut = milieu + 1; // On cherche dans la moitié supérieure
        } else {
            fin = milieu - 1; // On cherche dans la moitié inférieure
        }
    }

    // 4. Affichage du résultat final
    printf("\nResultat : ");
    if (trouve == 1) {
        printf("entier present\n");
    } else {
        printf("entier absent\n");
    }

    return 0;
}