#include "filter.h"
#include <stdio.h>
#include <string.h>

void filter(CLIENT *client[], int choix, int ligne){
    char search[25];
    printf("\n\ntapez le mot a rechercher: ");
    scanf("%s",search);
    int start = 0;
    int end = ligne-1;

    while (start < end){
        int middle = (start + end)/2;

        if(strncmp(client[middle]->nom ,search, strlen(search)) == 0){
            showFilter(client,choix,middle,search);

            return;
        }
        else if(strncmp(client[middle]->nom ,search, strlen(search))< 0){
            start = middle + 1;
        }
        else if(strncmp(client[middle]->nom ,search, strlen(search))> 0){
            end = middle;
        }

    }
    printf("aucun résultat");
}

void showFilter(CLIENT *client[], int choix,int middle, char *search){


    while(strncmp(client[middle]->nom ,search, strlen(search))==0){
        middle--;
    }
    middle++;
    while (strncmp(client[middle]->nom ,search, strlen(search))==0){
        printf(" %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
               client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
        middle++;
    }
}
