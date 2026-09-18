#include <stdio.h>
#include <string.h> // Nécessaire pour utiliser strcpy()

// 1. Définition de la structure
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note1;
    float note2;
};

int main() {
    // 2. Création d'un tableau de 5 éléments de cette structure
    struct Etudiant classe[5];

    // 3. Initialisation avec strcpy pour les chaînes de caractères
    // Étudiant 1
    strcpy(classe[0].nom, "Dupont");
    strcpy(classe[0].prenom, "Marie");
    strcpy(classe[0].adresse, "20, Boulevard Niels Bohr, Lyon");
    classe[0].note1 = 16.5;
    classe[0].note2 = 12.1;

    // Étudiant 2
    strcpy(classe[1].nom, "Martin");
    strcpy(classe[1].prenom, "Pierre");
    strcpy(classe[1].adresse, "22, Boulevard Niels Bohr, Lyon");
    classe[1].note1 = 14.0;
    classe[1].note2 = 14.1;

    // Étudiant 3
    strcpy(classe[2].nom, "Durand");
    strcpy(classe[2].prenom, "Alice");
    strcpy(classe[2].adresse, "15, Rue de la Republique, Paris");
    classe[2].note1 = 15.5;
    classe[2].note2 = 16.0;

    // Étudiant 4
    strcpy(classe[3].nom, "Lefebvre");
    strcpy(classe[3].prenom, "Hugo");
    strcpy(classe[3].adresse, "8, Avenue des Champs, Lille");
    classe[3].note1 = 11.0;
    classe[3].note2 = 9.5;

    // Étudiant 5
    strcpy(classe[4].nom, "Moreau");
    strcpy(classe[4].prenom, "Sophie");
    strcpy(classe[4].adresse, "3, Place du Capitole, Toulouse");
    classe[4].note1 = 18.0;
    classe[4].note2 = 17.5;

    // 4. Affichage des données
    for (int i = 0; i < 5; i++) {
        printf("Etudiant.e %d :\n", i + 1);
        printf("Nom : %s\n", classe[i].nom);
        printf("Prenom : %s\n", classe[i].prenom);
        printf("Adresse : %s\n", classe[i].adresse);
        printf("Note 1 : %.1f\n", classe[i].note1);
        printf("Note 2 : %.1f\n\n", classe[i].note2);
    }

    return 0;
}