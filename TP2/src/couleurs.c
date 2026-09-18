#include <stdio.h>

// 1. Définition de la structure pour un format RGBA (1 octet par composant)
struct Couleur {
    unsigned char r; // Rouge
    unsigned char g; // Vert
    unsigned char b; // Bleu
    unsigned char a; // Alpha (opacité)
};

int main() {
    // 2. Création et initialisation d'un tableau de 10 couleurs en hexadécimal
    struct Couleur palette[10] = {
        {0xef, 0x78, 0x12, 0xff}, // Couleur 1 de l'exemple (239, 120, 18, 255)
        {0x2c, 0xc8, 0x64, 0xff}, // Couleur 2 de l'exemple (44, 200, 100, 255)
        {0xff, 0x00, 0x00, 0xff}, // Rouge pur
        {0x00, 0xff, 0x00, 0xff}, // Vert pur
        {0x00, 0x00, 0xff, 0xff}, // Bleu pur
        {0xff, 0xff, 0xff, 0xff}, // Blanc
        {0x00, 0x00, 0x00, 0xff}, // Noir
        {0x80, 0x80, 0x80, 0x80}, // Gris semi-transparent
        {0xff, 0xa5, 0x00, 0xff}, // Orange
        {0x4b, 0x00, 0x82, 0xaa}  // Indigo un peu transparent
    };

    // 3. Affichage des valeurs en base 10 (décimal)
    for (int i = 0; i < 10; i++) {
        printf("Couleur %d :\n", i + 1);
        // On utilise %d pour afficher l'octet sous forme d'entier décimal
        printf("Rouge : %d\n", palette[i].r);
        printf("Vert : %d\n", palette[i].g);
        printf("Bleu : %d\n", palette[i].b);
        printf("Alpha : %d\n\n", palette[i].a);
    }

    return 0;
}