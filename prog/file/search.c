#include "search.h"
#include "trier.h"
#include <stdio.h>
#include <string.h>

int search(CLIENT *client[], int choix, int *ligne){//Liam Lucas---fonction de recherche par dichotomique
    char search[50];
    printf("Tapez un mot a rechercher: ");//demande de string a rechercher
    scanf("%s",search);
    int start = 0;
    int end = *ligne-1;// délimite début et fin de tableau

    switch (choix) { //switch permettant de choisir recherche:nom, prenom, telephone et email
        case 1:
            trie(client,choix,0,*ligne-1);
            while (start < end){
                int middle = (start + end)/2;

                if(strcmp(client[middle]->nom ,search) == 0){ //si le nom de la struct est égal au mot recherché on affiche le client

                    printf("\n  %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                           client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                    return middle;
                }
                else if(strcmp(client[middle]->nom ,search)< 0){        // si le mot est plus petit que le mot recherché l'indice de début
                    start = middle + 1;                                 // est égal a l'indice du milieu
                }
                else if(strcmp(client[middle]->nom ,search)> 0){        // le contraire
                    end = middle;
                }

            }
            break;
        case 2:
            trie(client,choix,0,*ligne-1);
            while (start < end){
                int middle = (start + end)/2;

                if(strcmp(client[middle]->prenom ,search) == 0){
                    //printf("salut");
                    printf("\n  %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                           client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                    return middle;
                }
                else if(strcmp(client[middle]->prenom ,search)< 0){
                    start = middle + 1;
                }
                else if(strcmp(client[middle]->prenom ,search)> 0){
                    end = middle;
                }

            }
            break;
        case 3:
            trie(client,5,0,*ligne-1);
            while (start < end){
                int middle = (start + end)/2;

                if(strcmp(client[middle]->telephone ,search) == 0){
                    printf("\n  %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                           client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                    return middle;
                }
                else if(strcmp(client[middle]->telephone ,search)< 0){
                    start = middle + 1;
                }
                else if(strcmp(client[middle]->telephone ,search)> 0){
                    end = middle;
                }

            }
            break;
        case 4:
            trie(client,6,0,*ligne-1);
            while (start < end){
                int middle = (start + end)/2;

                if(strcmp(client[middle]->email ,search) == 0){
                    //printf("salut");
                    printf("\n  %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                           client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                    return middle;
                }
                else if(strcmp(client[middle]->email ,search)< 0){
                    start = middle + 1;
                }
                else if(strcmp(client[middle]->email ,search)> 0){
                    end = middle;
                }

            }
            break;

        default:
            return -1;
    }

    printf("mot non trouve");
    return -1;
}

