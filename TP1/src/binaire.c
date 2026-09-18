#include <stdio.h>

int main() {
    // Les nombres à tester selon l'énoncé
    int valeurs[5] = {0, 4096, 65536, 65535, 1024};

    for (int v = 0; v < 5; v++) {
        int nombre = valeurs[v];
        printf("%6d = ", nombre);

        // On boucle sur les 32 bits d'un entier, du bit de poids fort (31) au bit de poids faible (0)
        for (int i = 31; i >= 0; i--) {
            // On décale le bit visé tout à droite, et on utilise le masque & 1 pour l'isoler
            int bit = (nombre >> i) & 1;
            printf("%d", bit);
            
            // Petit bonus esthétique : un espace tous les 4 bits pour la lisibilité
            if (i % 4 == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}