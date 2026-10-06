#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
struct BMPHeader {
    unsigned short type;
    unsigned int taille_fichier;
    unsigned short reserve1;
    unsigned short reserve2;
    unsigned int offset_donnees;
    unsigned int taille_entete_info;
    int largeur;
    int hauteur;
    unsigned short plans;
    unsigned short bpp; // Bits par pixel (24 ou 32)
    unsigned int compression;
};
#pragma pack(pop)

int lire_couleurs_bmp(const char *chemin_fichier, struct Couleur *couleurs, int max_couleurs) {
    FILE *f = fopen(chemin_fichier, "rb");
    if (!f) {
        perror("fopen BMP");
        return -1;
    }

    struct BMPHeader header;
    if (fread(&header, sizeof(struct BMPHeader), 1, f) != 1) {
        fclose(f);
        return -1;
    }

    if (header.type != 0x4D42) { // "BM"
        printf("Erreur : le fichier n'est pas un BMP valide.\n");
        fclose(f);
        return -1;
    }

    fseek(f, header.offset_donnees, SEEK_SET);

    int count = 0;
    int bytes_per_pixel = header.bpp / 8;

    while (count < max_couleurs) {
        unsigned char buffer[4];
        if (fread(buffer, 1, bytes_per_pixel, f) != (size_t)bytes_per_pixel) {
            break;
        }

        // Dans un fichier BMP, l'ordre des canaux est B, G, R, (A)
        couleurs[count].b = buffer[0];
        couleurs[count].g = buffer[1];
        couleurs[count].r = buffer[2];
        couleurs[count].a = (bytes_per_pixel == 4) ? buffer[3] : 0xFF;
        count++;
    }

    fclose(f);
    return count;
}