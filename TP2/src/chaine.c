#include <stdio.h>
// Attention : on n'inclut surtout pas <string.h> ici !

int main() {
    // Initialisation des chaînes (on prévoit des tableaux assez grands)
    char chaine1[100] = "Hello";
    char chaine2[] = " World!";
    char chaine_copie[100];
    char chaine_concat[100];

    // 1. Calcul du nombre de caractères dans chaine1
    int longueur = 0;
    while (chaine1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de la chaine '%s' : %d caracteres\n", chaine1, longueur);

    // 2. Copie de chaine1 dans chaine_copie
    int i = 0;
    while (chaine1[i] != '\0') {
        chaine_copie[i] = chaine1[i];
        i++;
    }
    chaine_copie[i] = '\0'; // Toujours clore manuellement la nouvelle chaîne
    printf("Chaine copiee : '%s'\n", chaine_copie);

    // 3. Concaténation de chaine1 et chaine2 dans chaine_concat
    int j = 0;
    
    // Étape A : copier la première chaîne
    while (chaine1[j] != '\0') {
        chaine_concat[j] = chaine1[j];
        j++;
    }
    
    // Étape B : ajouter la deuxième chaîne à la suite
    int k = 0;
    while (chaine2[k] != '\0') {
        chaine_concat[j] = chaine2[k];
        j++;
        k++;
    }
    chaine_concat[j] = '\0'; // Clôturer la chaîne finale
    printf("Chaine concatenee : '%s'\n", chaine_concat);

    return 0;
}