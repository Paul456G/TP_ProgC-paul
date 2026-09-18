#include <stdio.h>

int main() {
    int somme = 0;

    // 1. Boucle de 1 à 1000
    for (int i = 1; i <= 1000; i++) {
        
        // 2. Si divisible par 11, on ignore et on passe directement au nombre suivant
        if (i % 11 == 0) {
            continue;
        }

        // 2 (suite). Si divisible par 5 ou par 7, on l'ajoute à la somme
        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
        }

        // 3. Si la somme dépasse 5000, on arrête immédiatement la boucle
        if (somme > 5000) {
            break;
        }
    }

    // 4. On affiche la somme finale
    printf("La somme finale est : %d\n", somme);

    return 0;
}