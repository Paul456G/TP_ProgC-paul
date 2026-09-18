#include <stdio.h>

int main() {
    // 1. Déclaration et initialisation des variables
    char c = 'A';
    short s = 255;
    // On initialise i et f pour coller exactement à l'exemple du sujet
    int i = 0xa47865ff; 
    long int li = 123456789L;
    long long int lli = 9876543210LL;
    float f = 2.0f; // 2.0 en binaire IEEE-754 donne 0x40000000
    double d = 3.14159;
    long double ld = 2.71828L;

    // 2. Déclaration des pointeurs associés
    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pli = &li;
    long long int *plli = &lli;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    // 3. Affichage AVANT manipulation
    printf("Avant la manipulation :\n");
    // %p affiche l'adresse du pointeur. 
    // %x affiche la valeur en hexadécimal.
    printf("Adresse de c : %p, Valeur de c : %x\n", (void*)pc, *pc);
    printf("Adresse de s : %p, Valeur de s : %x\n", (void*)ps, *ps);
    printf("Adresse de i : %p, Valeur de i : %x\n", (void*)pi, *pi);
    printf("Adresse de li : %p, Valeur de li : %lx\n", (void*)pli, *pli);
    printf("Adresse de lli : %p, Valeur de lli : %llx\n", (void*)plli, *plli);
    // Pour afficher les flottants en hexadécimal (comme demandé dans l'exemple), on lit la mémoire comme un entier
    printf("Adresse de f : %p, Valeur de f : %x\n", (void*)pf, *(unsigned int*)pf);
    printf("Adresse de d : %p, Valeur de d : %llx\n\n", (void*)pd, *(unsigned long long*)pd);

    // 4. Manipulation des variables VIA leurs pointeurs
    *pc = 'B';
    *ps = 512;
    *pi = 0xa47865fe; // Valeur de l'exemple après manipulation
    *pli = 987654321L;
    *plli = 1234567890LL;
    *pf = 1.0f; // 1.0 en IEEE-754 donne 0x3f800000 (valeur de l'exemple)
    *pd = 1.61803;
    *pld = 1.41421L;

    // 5. Affichage APRÈS manipulation
    printf("Apres la manipulation :\n");
    printf("Adresse de c : %p, Valeur de c : %x\n", (void*)pc, *pc);
    printf("Adresse de s : %p, Valeur de s : %x\n", (void*)ps, *ps);
    printf("Adresse de i : %p, Valeur de i : %x\n", (void*)pi, *pi);
    printf("Adresse de li : %p, Valeur de li : %lx\n", (void*)pli, *pli);
    printf("Adresse de lli : %p, Valeur de lli : %llx\n", (void*)plli, *plli);
    printf("Adresse de f : %p, Valeur de f : %x\n", (void*)pf, *(unsigned int*)pf);
    printf("Adresse de d : %p, Valeur de d : %llx\n", (void*)pd, *(unsigned long long*)pd);

    return 0;
}