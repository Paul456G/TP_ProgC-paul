#include <stdio.h>
#include <string.h>

int main() {
    char nom_fichier[100];
    char phrase[256];
    char ligne[1024];

    // 1. Saisie des informations par l'utilisateur
    printf("Entrez le nom du fichier dans lequel vous souhaitez effectuer la recherche : ");
    scanf("%99s", nom_fichier);

    // Vider le buffer du clavier
    while(getchar() != '\n');

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);

    // Supprimer le saut de ligne '\n' capturé par fgets à la fin de la phrase
    size_t len_phrase = strlen(phrase);
    if (len_phrase > 0 && phrase[len_phrase - 1] == '\n') {
        phrase[len_phrase - 1] = '\0';
    }

    // 2. Ouverture du fichier en mode lecture
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s.\n", nom_fichier);
        return 1;
    }

    printf("\nResultats de la recherche :\n");
    int numero_ligne = 1;
    int trouve = 0;

    // 3. Parcours du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        // Supprimer le '\n' de fin de ligne pour éviter les faux problèmes de comparaison
        size_t len_ligne = strlen(ligne);
        if (len_ligne > 0 && ligne[len_ligne - 1] == '\n') {
            ligne[len_ligne - 1] = '\0';
        }

        // Compter les occurrences de la phrase dans la ligne courante
        int occurrences = 0;
        char *ptr = ligne;
        
        // strstr cherche la première occurrence et retourne un pointeur vers celle-ci
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            occurrences++;
            ptr += strlen(phrase); // Avancer le pointeur pour chercher la suivante sur la même ligne
        }

        // Si la phrase apparaît au moins une fois, on affiche le résultat formaté
        if (occurrences > 0) {
            printf("Ligne %d, %d fois\n", numero_ligne, occurrences);
            trouve = 1;
        }

        numero_ligne++;
    }

    fclose(f);

    if (!trouve) {
        printf("La phrase n'a pas ete trouvee dans le fichier.\n");
    }

    return 0;
}