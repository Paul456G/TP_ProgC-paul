CC = gcc
CFLAGS = -Wall -Wextra

all: repertoire serveur client

repertoire: repertoire.c main.c
	$(CC) $(CFLAGS) -o repertoire repertoire.c main.c

serveur: serveur.c
	$(CC) $(CFLAGS) -o serveur serveur.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm -f repertoire serveur client