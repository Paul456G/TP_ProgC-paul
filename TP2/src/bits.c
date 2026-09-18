#include <stdio.h>

int main() {
    // Initialisation de d avec une valeur de test.
    // (1 << 28) | (1 << 12) force le 4ème et le 20ème bit de gauche à 1.
    // Cela correspond à la valeur décimale 268439552.
    unsigned int d = 268439552; 

    // Décalage vers la droite pour placer le bit ciblé en position 0, puis masquage avec & 1
    int bit4_gauche = (d >> 28) & 1;
    int bit20_gauche = (d >> 12) & 1;

    // Si les deux bits valent 1, 1 & 1 donne 1. Dans tous les autres cas, cela donne 0.
    printf("%d\n", bit4_gauche & bit20_gauche);

    return 0;
}