#include <stdio.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Définition de la structure Étudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note1;
    float note2;
};

// Prototypes des fonctions d'exercices
void exo4_1();
void exo4_2();
void exo4_3();
void exo4_7();

int main() {
    int choix;
    
    printf("Menu principal TP4 :\n");
    printf("1. Exercice 4.1 (Calcul avec operateurs)\n");
    printf("2. Exercice 4.2 (Gestion de fichiers)\n");
    printf("3. Exercice 4.3 (Base de donnees etudiante)\n");
    printf("7. Exercice 4.7 (Gestion d'une liste de couleurs)\n");
    printf("Entrez le numero de l'exercice a executer : ");
    scanf("%d", &choix);
    
    switch(choix) {
        case 1: exo4_1(); break;
        case 2: exo4_2(); break;
        case 3: exo4_3(); break;
        case 7: exo4_7(); break;
        default: printf("Choix invalide.\n"); break;
    }
    
    return 0;
}

void exo4_1() {
    int num1, num2;
    char op;
    
    printf("\n--- Exercice 4.1 ---\n");
    printf("Entrez num1 : ");
    scanf("%d", &num1);
    printf("Entrez num2 : ");
    scanf("%d", &num2);
    
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);
    
    printf("Resultat : ");
    switch(op) {
        case '+': printf("%d\n", somme(num1, num2)); break;
        case '-': printf("%d\n", difference(num1, num2)); break;
        case '*': printf("%d\n", produit(num1, num2)); break;
        case '/': printf("%d\n", quotient(num1, num2)); break;
        case '%': printf("%d\n", modulo(num1, num2)); break;
        case '&': printf("%d\n", et_logique(num1, num2)); break;
        case '|': printf("%d\n", ou_logique(num1, num2)); break;
        case '~': printf("%d (negation de num1)\n", negation(num1)); break;
        default: printf("Operateur non reconnu.\n"); break;
    }
}

void exo4_2() {
    int choix;
    char nom_fichier[100];
    char message[256];

    printf("\nQue souhaitez-vous faire ?\n");
    printf("1. Lire un fichier\n");
    printf("2. Ecrire dans un fichier\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    while(getchar() != '\n'); 

    if (choix == 1) {
        printf("\nEntrez le nom du fichier a lire : ");
        scanf("%99s", nom_fichier);
        lire_fichier(nom_fichier);
    } 
    else if (choix == 2) {
        printf("\nEntrez le nom du fichier dans lequel vous souhaitez ecrire : ");
        scanf("%99s", nom_fichier);
        
        while(getchar() != '\n');
        
        printf("Entrez le message a ecrire : ");
        fgets(message, sizeof(message), stdin);
        
        size_t len = strlen(message);
        if (len > 0 && message[len-1] == '\n') {
            message[len-1] = '\0';
        }
        
        ecrire_dans_fichier(nom_fichier, message);
    } 
    else {
        printf("Choix invalide.\n");
    }
}

void exo4_3() {
    struct Etudiant classe[5];

    printf("\n--- Exercice 4.3 : Base de donnees etudiante ---\n");
    
    for (int i = 0; i < 5; i++) {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);
        
        printf("Nom : ");
        scanf("%49s", classe[i].nom);
        
        printf("Prenom : ");
        scanf("%49s", classe[i].prenom);
        
        while(getchar() != '\n');
        
        printf("Adresse : ");
        fgets(classe[i].adresse, sizeof(classe[i].adresse), stdin);
        size_t len = strlen(classe[i].adresse);
        if (len > 0 && classe[i].adresse[len - 1] == '\n') {
            classe[i].adresse[len - 1] = '\0';
        }
        
        printf("Note 1 : ");
        scanf("%f", &classe[i].note1);
        
        printf("Note 2 : ");
        scanf("%f", &classe[i].note2);
    }

    FILE *fichier = fopen("etudiant.txt", "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible de creer le fichier etudiant.txt\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(fichier, "Nom : %s | Prenom : %s | Adresse : %s | Note 1 : %.2f | Note 2 : %.2f\n",
                classe[i].nom, classe[i].prenom, classe[i].adresse, classe[i].note1, classe[i].note2);
    }
    
    fclose(fichier);
    printf("\nLes details des etudiants ont ete enregistres dans le fichier etudiant.txt.\n");
}

void exo4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);

    printf("\n--- Exercice 4.7 : Liste chaînée de couleurs ---\n");

    struct couleur palette_test[10] = {
        {0xFF, 0x00, 0x00, 0xFF},
        {0x00, 0xFF, 0x00, 0xFF},
        {0x00, 0x00, 0xFF, 0xFF},
        {0xFF, 0xFF, 0x00, 0xFF},
        {0xFF, 0x00, 0xFF, 0xFF},
        {0x00, 0xFF, 0xFF, 0xFF},
        {0xFF, 0xFF, 0xFF, 0xFF},
        {0x00, 0x00, 0x00, 0xFF},
        {0x80, 0x80, 0x80, 0xFF},
        {0xFF, 0xA5, 0x00, 0xFF}
    };

    for (int i = 0; i < 10; i++) {
        insertion(&palette_test[i], &ma_liste);
    }

    printf("Liste des couleurs enregistrees :\n");
    parcours(&ma_liste);
}