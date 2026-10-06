#include "serveur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

static int server_fd = -1;

void handle_sigint(int sig) {
    (void)sig;
    if (server_fd != -1) close(server_fd);
    printf("\nSignal Ctrl+C capture. Sortie du programme.\n");
    exit(0);
}

void recois_numeros_calcule(const char *requete, char *reponse) {
    char op;
    float num1, num2;
    const char *debut = requete;

    if (strncmp(debut, "calcule :", 9) == 0) {
        debut += 9;
    }

    if (sscanf(debut, " %c %f %f", &op, &num1, &num2) == 3) {
        float res = 0;
        int valide = 1;
        switch (op) {
            case '+': res = num1 + num2; break;
            case '-': res = num1 - num2; break;
            case '*': res = num1 * num2; break;
            case '/':
                if (num2 != 0) res = num1 / num2;
                else valide = 0;
                break;
            default: valide = 0; break;
        }
        if (valide) snprintf(reponse, BUFFER_SIZE, "calcule : %.2f", res);
        else snprintf(reponse, BUFFER_SIZE, "Erreur operation");
    } else {
        snprintf(reponse, BUFFER_SIZE, "Format invalide");
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Serveur en attente de connexions sur le port %d...\n", PORT);

    while (1) {
        int client_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_sock < 0) continue;

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(client_sock, buffer, sizeof(buffer) - 10);
            if (valread <= 0) break;

            printf("Message recu: %s\n", buffer);

            char reponse[BUFFER_SIZE];
            if (strncmp(buffer, "calcule :", 9) == 0 || buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/') {
                recois_numeros_calcule(buffer, reponse);
            } else {
                snprintf(reponse, sizeof(reponse), "message: %s", buffer);
            }

            write(client_sock, reponse, strlen(reponse));
        }
        close(client_sock);
    }
    return 0;
}