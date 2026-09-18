#include <stdio.h>

int main() {
    // 1. Initialisation du tableau avec les 10 phrases de l'exemple
    char phrases[10][100] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    // 2. La phrase à rechercher (tu peux tester avec "Je préfère le Python." pour voir l'échec)
    char recherche[] = "La programmation en C est amusante.";
    
    int phrase_trouvee = 0; // 0 = non, 1 = oui

    // 3. Parcours du tableau de 10 phrases
    for (int i = 0; i < 10; i++) {
        int correspond = 1; // On part du principe que c'est la bonne phrase
        int j = 0;

        // Comparaison caractère par caractère
        // On s'arrête si on trouve une différence, ou si on arrive à la fin des deux chaînes
        while (phrases[i][j] != '\0' || recherche[j] != '\0') {
            if (phrases[i][j] != recherche[j]) {
                correspond = 0; // Différence détectée !
                break;          // On casse le while, on passe à la phrase suivante
            }
            j++;
        }

        // Si après l'analyse, 'correspond' est toujours à 1, c'est un match parfait
        if (correspond == 1) {
            phrase_trouvee = 1;
            break; // On a trouvé, on casse le for, inutile de vérifier le reste du tableau
        }
    }

    // 4. Affichage du résultat selon l'énoncé
    if (phrase_trouvee == 1) {
        printf("Phrase trouvee\n");
    } else {
        printf("Phrase non trouvee\n");
    }

    return 0;
}