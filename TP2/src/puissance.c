#include <stdio.h>

int main() {
    int a = 2; // La base (tu peux changer cette valeur)
    int b = 3; // L'exposant (tu peux changer cette valeur)
    long long resultat = 1; // On utilise un entier long pour éviter de dépasser la capacité si on teste de grands nombres

    // On multiplie 'a' par lui-même 'b' fois
    for (int i = 0; i < b; i++) {
        resultat *= a;
    }

    // Affichage du résultat à l'écran
    printf("%d a la puissance %d est egal a %lld\n", a, b, resultat);

    return 0;
}