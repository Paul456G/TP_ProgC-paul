#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void init_liste(struct liste_couleurs *liste) {
    liste->tete = NULL;
}

void insertion(struct couleur *c, struct liste_couleurs *liste) {
    // 1. Allocation dynamique d'un nouveau maillon
    struct maillon *nouveau = (struct maillon *)malloc(sizeof(struct maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire !\n");
        return;
    }
    
    // 2. Copie des données de la couleur
    nouveau->col = *c;
    nouveau->suivant = NULL;

    // 3. Insertion dans la liste (ici en tête pour faire simple et rapide)
    nouveau->suivant = liste->tete;
    liste->tete = nouveau;
}

void parcours(struct liste_couleurs *liste) {
    struct maillon *courant = liste->tete;
    int index = 1;
    
    while (courant != NULL) {
        printf("Couleur %d -> R: 0x%02x, G: 0x%02x, B: 0x%02x, A: 0x%02x\n",
               index,
               courant->col.r,
               courant->col.g,
               courant->col.b,
               courant->col.a);
        courant = courant->suivant;
        index++;
    }
}