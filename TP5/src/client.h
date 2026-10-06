#ifndef CLIENT_H
#define CLIENT_H

#define PORT 8080
#define BUFFER_SIZE 1024

void envoie_operateur_numeros(int sock, char op, float num1, float num2, char *reponse);

#endif