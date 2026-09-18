#include <stdio.h>

// Fonction générique pour parcourir et afficher les octets
void afficher_octets(const char* nom_type, void* adresse, size_t taille) {
    // On force la lecture de l'adresse octet par octet
    unsigned char* pointeur = (unsigned char*)adresse;
    
    printf("Octets de %s :\n ", nom_type);
    for (size_t i = 0; i < taille; i++) {
        // %02x affiche la valeur en hexadécimal sur 2 caractères avec un zéro si besoin
        printf("%02x ", pointeur[i]);
    }
    printf("\n\n");
}

int main() {
    // 1. Déclaration et initialisation des variables
    // On utilise des valeurs hexadécimales explicites pour voir l'ordre des octets (le boutisme)
    short v_short = 0x0302;
    int v_int = 0x04030201;
    long int v_long = 0x0807060504030201L;
    
    float v_float = 1.2f;       
    double v_double = 1.2345;   
    long double v_ldouble = 1.23456L;

    // 2. Appel de la fonction avec l'adresse (&) et la taille (sizeof) de chaque variable
    afficher_octets("short", &v_short, sizeof(v_short));
    afficher_octets("int", &v_int, sizeof(v_int));
    afficher_octets("long int", &v_long, sizeof(v_long));
    afficher_octets("float", &v_float, sizeof(v_float));
    afficher_octets("double", &v_double, sizeof(v_double));
    afficher_octets("long double", &v_ldouble, sizeof(v_ldouble));

    return 0;
}