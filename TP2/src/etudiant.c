#include <stdio.h>

int main() {
    // Déclaration et initialisation des tableaux pour 5 étudiants
    char *noms_prenoms[5] = {
        "Dupont Marie",
        "Martin Pierre",
        "Durand Alice",
        "Lefebvre Hugo",
        "Moreau Sophie"
    };

    char *adresses[5] = {
        "20, Boulevard Niels Bohr, Lyon",
        "22, Boulevard Niels Bohr, Lyon",
        "15, Rue de la Republique, Paris",
        "8, Avenue des Champs, Lille",
        "3, Place du Capitole, Toulouse"
    };

    float notes_prog_c[5] = {16.5, 14.0, 15.5, 11.0, 18.0};
    float notes_sys_os[5] = {12.1, 14.1, 16.0, 9.5, 17.5};

    // Parcours des tableaux pour afficher les détails
    for (int i = 0; i < 5; i++) {
        // Utilisation de l'arithmétique des pointeurs *(tableau + i) comme suggéré
        printf("Etudiant.e %d :\n", i + 1);
        printf("Nom et prenom : %s\n", *(noms_prenoms + i));
        printf("Adresse : %s\n", *(adresses + i));
        printf("Note Programmation C : %.1f\n", *(notes_prog_c + i));
        printf("Note Systeme d'exploitation : %.1f\n\n", *(notes_sys_os + i));
    }

    return 0;
}