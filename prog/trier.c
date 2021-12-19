#include "trier.h"
#include <string.h>


void trie(CLIENT *client[], int choix, int gauche, int droite) {
    int i, j;
    char *pivot;

    pivot = client[(gauche + droite) / 2]->nom;
    i = gauche;
    j = droite;

    do {
        while ((strcmp(client[i]->nom, pivot) <0) && (i < droite)) {
            i++;
        }
        while ((strcmp(client[j]->nom ,pivot)>0) && (j > gauche)) {
            j--;
        }
        if (i <= j) {
            swap(client, i, j);
            i++;
            j--;
        }
    } while (i <= j);


    if (gauche < j) {
        trie(client, choix, gauche, j);
    }

    if (i < droite) {
        trie(client, choix, i, droite);
    }
}

void swap(CLIENT *client[], int pos1, int pos2) {
    CLIENT *temp;
    temp = client[pos1];
    client[pos1] = client[pos2];
    client[pos2] = temp;
}