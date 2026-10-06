#include "client.h"
#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Utilisation : %s <chemin_image_bmp> [nb_couleurs (max 30)]\n", argv[0]);
        return 1;
    }

    int nb_demande = 10; // Valeur par défaut de l'exercice 6.1
    if (argc >= 3) {
        nb_demande = atoi(argv[2]);
        if (nb_demande <= 0 || nb_demande > 30) {
            printf("Le nombre de couleurs doit être compris entre 1 et 30. Valeur par défaut fixée à 10.\n");
            nb_demande = 10;
        }
    }

    struct Couleur tab_couleurs[30];
    int nb_recuperees = lire_couleurs_bmp(argv[1], tab_couleurs, nb_demande);
    if (nb_recuperees <= 0) {
        printf("Impossible d'extraire les couleurs du fichier %s\n", argv[1]);
        return 1;
    }

    // Formatage du message au format JSON (Exercice 6.3)
    char json_buffer[BUFFER_SIZE];
    int offset = snprintf(json_buffer, sizeof(json_buffer), "{\n  \"code\": \"couleurs\",\n  \"valeurs\": [");

    for (int i = 0; i < nb_recuperees; i++) {
        char separateur = (i == nb_recuperees - 1) ? ' ' : ',';
        offset += snprintf(json_buffer + offset, sizeof(json_buffer) - offset,
                           "\"#%02x%02x%02x\"%c",
                           tab_couleurs[i].r, tab_couleurs[i].g, tab_couleurs[i].b, separateur);
    }
    snprintf(json_buffer + offset, sizeof(json_buffer) - offset, "]\n}");

    // Connexion réseau
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Erreur de connexion au serveur");
        return 1;
    }

    write(sock, json_buffer, strlen(json_buffer));

    char reponse[BUFFER_SIZE];
    memset(reponse, 0, sizeof(reponse));
    read(sock, reponse, sizeof(reponse) - 1);
    printf("Réponse serveur : %s\n", reponse);

    close(sock);
    return 0;
}