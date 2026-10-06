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
    printf("\nSignal Ctrl+C capturé. Sortie du serveur.\n");
    exit(0);
}

void generer_svg_et_afficher(char couleurs[][16], int total) {
    FILE *f = fopen("resultat.svg", "w");
    if (!f) return;

    int svg_largeur = total * 55 + 20;
    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"200\">\n", svg_largeur);
    fprintf(f, "  <rect width=\"100%%\" height=\"100%%\" fill=\"#f0f0f0\"/>\n");

    for (int i = 0; i < total; i++) {
        int x = 20 + i * 55;
        fprintf(f, "  <rect x=\"%d\" y=\"30\" width=\"45\" height=\"100\" fill=\"%s\" rx=\"5\"/>\n", x, couleurs[i]);
        fprintf(f, "  <text x=\"%d\" y=\"150\" font-size=\"10\" font-family=\"monospace\">%s</text>\n", x, couleurs[i]);
    }
    fprintf(f, "</svg>\n");
    fclose(f);

    printf("Graphique SVG généré dans resultat.svg. Ouverture du navigateur...\n");
    // Essaie d'ouvrir firefox ou l'outil d'affichage par défaut
    if (system("which firefox > /dev/null 2>&1") == 0) {
        system("firefox resultat.svg > /dev/null 2>&1 &");
    } else {
        system("xdg-open resultat.svg > /dev/null 2>&1 &");
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
    printf("Serveur en écoute sur le port %d...\n", PORT);

    while (1) {
        int client_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_sock < 0) continue;

        memset(buffer, 0, sizeof(buffer));
        int valread = read(client_sock, buffer, sizeof(buffer) - 1);
        if (valread > 0) {
            printf("Message JSON reçu :\n%s\n", buffer);

            if (strstr(buffer, "\"code\": \"couleurs\"") != NULL) {
                char couleurs[30][16];
                int nb_couleurs = 0;

                char *ptr = strstr(buffer, "\"valeurs\":");
                if (ptr) {
                    ptr = strchr(ptr, '[');
                    while (ptr && *ptr != ']' && nb_couleurs < 30) {
                        char *debut = strchr(ptr, '"');
                        if (!debut) break;
                        char *fin = strchr(debut + 1, '"');
                        if (!fin) break;

                        int len = fin - (debut + 1);
                        strncpy(couleurs[nb_couleurs], debut + 1, len);
                        couleurs[nb_couleurs][len] = '\0';
                        nb_couleurs++;

                        ptr = fin + 1;
                    }
                }

                printf("Nombre de couleurs extraites : %d\n", nb_couleurs);
                generer_svg_et_afficher(couleurs, nb_couleurs);

                char reponse[] = "{\"status\": \"ok\", \"message\": \"Graphique genere\"}";
                write(client_sock, reponse, strlen(reponse));
            }
        }
        close(client_sock);
    }

    return 0;
}