CC = gcc
CFLAGS = -Wall -Wextra

all: serveur client

serveur: serveur.c
	$(CC) $(CFLAGS) -o serveur serveur.c

client: client.c bmp.c couleur.c
	$(CC) $(CFLAGS) -o client client.c bmp.c couleur.c

clean:
	rm -f serveur client resultat.svg