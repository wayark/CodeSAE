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
            pivot = client[(gauche + droite) / 2]->nom; //pivot choisis au milieu de la liste des clients
            do {
                while ((strcmp(client[i]->nom, pivot) <0) && (i < droite)) {    //si le mot est a gauche et plus petit que le pivot
                    i++;                                                        // i incrémente
                }
                while ((strcmp(client[j]->nom ,pivot)>0) && (j > gauche)) {  // si le mot est a droite et plus grand que le pivot
                    j--;                                                     // j décrémente
                }
                if (i <= j) {       //on échange les mot d'indice i et j car étant dans le mauvais coté du tableau
                    swap(client, i, j);
                    i++;
                    j--;
                }
            } while (i <= j);// tant que les deux indice ne se rencontre pas
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

    if (gauche < j) {               //pour éviter de rappeler la fonction si je tableau est trop petit
        trie(client, choix, gauche, j);
    }

    if (i < droite) {               // pareil
        trie(client, choix, i, droite);
    }
}

void swap(CLIENT *client[], int pos1, int pos2) {// fonction qui permet d'échanger la position des pointeurs pointant vers un client
    CLIENT *temp;
    temp = client[pos1];
    client[pos1] = client[pos2];
    client[pos2] = temp;
}