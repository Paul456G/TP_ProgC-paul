#ifndef BMP_H
#define BMP_H

#include "couleur.h"

int lire_couleurs_bmp(const char *chemin_fichier, struct Couleur *couleurs, int max_couleurs);

#endif