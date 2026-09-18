#ifndef LISTE_H
#define LISTE_H

// Structure pour une couleur RGB ou RGBA
struct couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

// Structure d'un maillon de la liste chaînée
struct maillon {
    struct couleur col;
    struct maillon *suivant;
};

// Structure principale de la liste
struct liste_couleurs {
    struct maillon *tete;
};

// Prototypes des fonctions
void init_liste(struct liste_couleurs *liste);
void insertion(struct couleur *c, struct liste_couleurs *liste);
void parcours(struct liste_couleurs *liste);

#endif