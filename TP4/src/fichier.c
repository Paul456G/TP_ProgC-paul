#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>

void lire_fichier(char *nom_de_fichier) {
    // Ouverture en mode lecture ("r" pour read)
    FILE *fichier = fopen(nom_de_fichier, "r");
    
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s (il n'existe peut-etre pas).\n", nom_de_fichier);
        return;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    
    char caractere;
    // Lecture caractère par caractère jusqu'à la fin du fichier (EOF)
    while ((caractere = fgetc(fichier)) != EOF) {
        putchar(caractere);
    }
    printf("\n");
    
    fclose(fichier);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    // Ouverture en mode ajout ("a" pour append) ou écriture ("w" pour write)
    // "w" recrée le fichier à zéro à chaque fois, ce qui correspond à l'exemple.
    FILE *fichier = fopen(nom_de_fichier, "w");
    
    if (fichier == NULL) {
        printf("Erreur : Impossible de creer le fichier %s.\n", nom_de_fichier);
        return;
    }

    fprintf(fichier, "%s\n", message);
    fclose(fichier);
    
    printf("Le message a ete ecrit dans le fichier %s.\n", nom_de_fichier);
}