#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Définition de la structure pour une couleur RGBA (un octet par composant)
struct Couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

// Structure pour associer une couleur distincte à son compteur d'occurrences
struct CouleurCompteur {
    struct Couleur couleur;
    int compteur;
};

int main() {
    struct Couleur tableau[100];
    struct CouleurCompteur distinctes[100];
    int nb_distinctes = 0;

    srand(time(NULL));

    // Remplissage du tableau avec 100 couleurs aléatoires 
    // (on restreint les valeurs pour générer facilement des doublons visibles)
    for (int i = 0; i < 100; i++) {
        tableau[i].r = (unsigned char)(rand() % 5);
        tableau[i].g = (unsigned char)(rand() % 5);
        tableau[i].b = (unsigned char)(rand() % 5);
        tableau[i].a = 0xff;
    }

    // Algorithme de comptage des couleurs distinctes
    for (int i = 0; i < 100; i++) {
        int trouve = 0;
        for (int j = 0; j < nb_distinctes; j++) {
            if (distinctes[j].couleur.r == tableau[i].r &&
                distinctes[j].couleur.g == tableau[i].g &&
                distinctes[j].couleur.b == tableau[i].b &&
                distinctes[j].couleur.a == tableau[i].a) {
                distinctes[j].compteur++;
                trouve = 1;
                break;
            }
        }
        // Si la couleur n'est pas encore dans le tableau des distinctes, on l'ajoute
        if (!trouve) {
            distinctes[nb_distinctes].couleur = tableau[i];
            distinctes[nb_distinctes].compteur = 1;
            nb_distinctes++;
        }
    }

    // Affichage des couleurs distinctes et de leurs occurrences
    printf("Liste des couleurs distinctes et de leurs occurrences :\n");
    for (int i = 0; i < nb_distinctes; i++) {
        printf("0x%02x 0x%02x 0x%02x 0x%02x : %d\n", 
               distinctes[i].couleur.r, 
               distinctes[i].couleur.g, 
               distinctes[i].couleur.b, 
               distinctes[i].couleur.a, 
               distinctes[i].compteur);
    }

    return 0;
}