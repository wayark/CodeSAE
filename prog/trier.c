#include "trier.h"



void trie(CLIENT *client[], int choix, int gauche, int droite) {
    int i, j;
    char pivot;

    pivot = client[(gauche+ droite )/2]->nom[0];
    i = gauche;
    j = droite;

    do {

        while ((client[i]->nom[0] <= pivot) && (i < droite)) {
            i++;
        }

        while ((client[j]->nom[0] > pivot) && (j > gauche)) {
            j--;
        }

        if (i <= j) {
            swap(client, i, j);
            i++;
            j--;
        }
    }while (i <= j);

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