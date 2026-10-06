#include "repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void lire_dossier(const char *nom_repertoire) {
    DIR *dp = opendir(nom_repertoire);
    if (!dp) return;
    struct dirent *entree;
    while ((entree = readdir(dp)) != NULL) {
        printf("%s\n", entree->d_name);
    }
    closedir(dp);
}

void lire_dossier_recursif(const char *nom_repertoire) {
    DIR *dp = opendir(nom_repertoire);
    if (!dp) return;
    struct dirent *entree;
    char chemin[1024];

    while ((entree = readdir(dp)) != NULL) {
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) continue;
        snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, entree->d_name);
        printf("%s\n", chemin);

        struct stat st;
        if (stat(chemin, &st) == 0 && S_ISDIR(st.st_mode)) {
            lire_dossier_recursif(chemin);
        }
    }
    closedir(dp);
}

void lire_dossier_iteratif(const char *nom_repertoire) {
    char file_dirs[512][1024];
    int debut = 0, fin = 0;

    strncpy(file_dirs[fin++], nom_repertoire, 1024);

    while (debut < fin) {
        char courant[1024];
        strncpy(courant, file_dirs[debut++], sizeof(courant));

        DIR *dp = opendir(courant);
        if (!dp) continue;

        struct dirent *entree;
        while ((entree = readdir(dp)) != NULL) {
            if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) continue;

            // Passer chemin à 2048 pour absorber courant (1024) + d_name (256)
            char chemin[2048];
            snprintf(chemin, sizeof(chemin), "%s/%s", courant, entree->d_name);
            printf("%s\n", chemin);

            struct stat st;
            if (stat(chemin, &st) == 0 && S_ISDIR(st.st_mode)) {
                if (fin < 512) {
                    strncpy(file_dirs[fin++], chemin, 1024);
                }
            }
        }
        closedir(dp);
    }
}