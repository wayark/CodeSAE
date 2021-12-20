#include "trier.h"
#include <string.h>
#include <stdio.h>


void trie(CLIENT *client[], int choix, int gauche, int droite) {
    int i, j;
    char *pivot;


    i = gauche;
    j = droite;

    switch (choix) {    //choix va permettre de trier selon le choix de l'utilisateur
        case 1:
            pivot = client[(gauche + droite) / 2]->nom;
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
            break;


        case 2:
            pivot = client[(gauche + droite) / 2]->prenom;
            do {
                while ((strcmp(client[i]->prenom, pivot) <0) && (i < droite)) {
                    i++;
                }
                while ((strcmp(client[j]->prenom ,pivot)>0) && (j > gauche)) {
                    j--;
                }
                if (i <= j) {
                    swap(client, i, j);
                    i++;
                    j--;
                }
            } while (i <= j);
            break;


        case 3:
            pivot = client[(gauche + droite) / 2]->codePostal;
            do {
                while ((strcmp(client[i]->codePostal, pivot) <0) && (i < droite)) {
                    i++;
                }
                while ((strcmp(client[j]->codePostal ,pivot)>0) && (j > gauche)) {
                    j--;
                }
                if (i <= j) {
                    swap(client, i, j);
                    i++;
                    j--;
                }
            } while (i <= j);
            break;


        case 4:
            pivot = client[(gauche + droite) / 2]->metier;
            do {
                while ((strcmp(client[i]->metier, pivot) <0) && (i < droite)) {
                    i++;
                }
                while ((strcmp(client[j]->metier ,pivot)>0) && (j > gauche)) {
                    j--;
                }
                if (i <= j) {
                    swap(client, i, j);
                    i++;
                    j--;
                }
            } while (i <= j);
            break;


        default:
            return;

    }

//----------------------Récurrence----------------------------------------------

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