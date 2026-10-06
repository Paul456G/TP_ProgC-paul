#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void envoie_operateur_numeros(int sock, char op, float num1, float num2, char *reponse) {
    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message), "calcule : %c %.2f %.2f", op, num1, num2);
    write(sock, message, strlen(message));
    memset(reponse, 0, BUFFER_SIZE);
    read(sock, reponse, BUFFER_SIZE - 1);
}

void traiter_notes_etudiants(int sock) {
    float notes[5] = {12.0f, 14.5f, 9.0f, 17.0f, 15.5f};
    char reponse[BUFFER_SIZE];
    float somme_totale = 0.0f;

    printf("\n--- Traitement des notes d'etudiants via le serveur ---\n");
    for (int i = 0; i < 5; i++) {
        envoie_operateur_numeros(sock, '+', somme_totale, notes[i], reponse);
        sscanf(reponse, "calcule : %f", &somme_totale);
    }
    printf("Somme totale des notes : %.2f\n", somme_totale);

    float moyenne = 0.0f;
    envoie_operateur_numeros(sock, '/', somme_totale, 5.0f, reponse);
    sscanf(reponse, "calcule : %f", &moyenne);
    printf("Moyenne de la classe : %.2f\n", moyenne);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connexion echouee");
        return 1;
    }

    int mode;
    printf("Choix :\n1. Envoi manuel\n2. Calcul de notes etudiants (Exo 5.6)\nChoix : ");
    if (scanf("%d", &mode) != 1) return 0;
    while (getchar() != '\n');

    if (mode == 2) {
        traiter_notes_etudiants(sock);
    } else {
        char saisie[BUFFER_SIZE];
        char reponse[BUFFER_SIZE];
        printf("Entrez un message ou une operation (ex: 'Bonjour' ou 'calcule : + 10 20') :\n> ");
        fgets(saisie, sizeof(saisie), stdin);
        saisie[strcspn(saisie, "\n")] = '\0';

        write(sock, saisie, strlen(saisie));
        memset(reponse, 0, sizeof(reponse));
        read(sock, reponse, sizeof(reponse) - 1);
        printf("%s\n", reponse);
    }

    close(sock);
    return 0;
}