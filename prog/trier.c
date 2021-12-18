#include "trier.h"
#include <string.h>
#include <stdio.h>


void trie(CLIENT *client[], int choix, int gauche, int droite) {

    if(gauche<droite) {

        int i, j, pi;
        char *pivot;
        *pivot = client[droite]->nom[0];
        i = gauche - 1;

        for (j = gauche; j <= droite - 1; j++) {
            if (strcmp(client[j]->nom, pivot) <= 0) {
                i++;
                swap(client, i, j);
            }
        }
        swap(client, i, j);
        pi = i + 1;
        trie(client, choix, gauche, pi-1);
        trie(client, choix, pi+1, droite);

    }

    /*pivot = client[(gauche+ droite )/2]->nom;
    i = gauche;
    j = droite;
    do {

        while ((strcmp(client[i]->nom, pivot) <= 0) && (i < droite)) {
            i++;
            printf("i :%d\n", i);
        }

        while ((strcmp(client[j]->nom, pivot) > 0) && (j > gauche)) {
            j--;
            printf("j :%d\n", j);
        }

        if (i <= j) {
            printf("i :%d  j :%d\n", i,j);
            swap(client, i, j);
            i++;
            j--;
        }

    }while (i <= j);

    if (gauche < j) {

        trier(client, choix, gauche, j);

    }
    if (i < droite) {

        trier(client, choix, i, droite);

    }*/
}

void swap(CLIENT *client[], int pos1, int pos2) {
    CLIENT *temp;
    temp = client[pos1];
    client[pos1] = client[pos2];
    client[pos2] = temp;
}