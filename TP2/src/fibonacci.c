#include <stdio.h>

int main() {
    int n = 7; // Valeur donnée dans l'exemple
    
    int u_n_moins_2 = 0; // Correspond à U0
    int u_n_moins_1 = 1; // Correspond à U1
    int u_n;             // Correspondra à Un

    printf("Suite de Fibonacci jusqu'a U%d : ", n);

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            printf("%d", u_n_moins_2);
        } else if (i == 1) {
            printf(", %d", u_n_moins_1);
        } else {
            // Calcul du terme courant Un
            u_n = u_n_moins_1 + u_n_moins_2;
            printf(", %d", u_n);
            
            // Décalage des variables pour la prochaine itération
            u_n_moins_2 = u_n_moins_1;
            u_n_moins_1 = u_n;
        }
    }
    
    printf("\n");

    return 0;
}