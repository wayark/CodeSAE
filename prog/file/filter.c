#include "filter.h"
#include <stdio.h>
#include <string.h>

void filter(CLIENT *client[], int choix, int ligne){ //même fonction que le search.c sauf strcmp a été remplacer par strncmp
    char search[30];
    printf("tapez un filtre: ");
    scanf("%s",search);
    int start = 0;
    int end = ligne-1;
    switch (choix) {//filtre en fonction du champ choisis
        case 1:
            while (start < end){
                int middle = (start + end)/2;

                if(strncmp(client[middle]->nom ,search, strlen(search)) == 0){// si le début du mot est égal au champ recherché
                    showFilter(client,choix,middle,search);// fonction qui montre tout les mot concerné

                    return;
                }
                else if(strncmp(client[middle]->nom ,search, strlen(search))< 0){
                    start = middle + 1;
                }
                else if(strncmp(client[middle]->nom ,search, strlen(search))> 0){
                    end = middle;
                }

            }
            break;
        case 2:
            while (start < end){
                int middle = (start + end)/2;

                if(strncmp(client[middle]->prenom ,search, strlen(search)) == 0){
                    showFilter(client,choix,middle,search);

                    return;
                }
                else if(strncmp(client[middle]->prenom ,search, strlen(search))< 0){
                    start = middle + 1;
                }
                else if(strncmp(client[middle]->prenom ,search, strlen(search))> 0){
                    end = middle;
                }

            }
            break;
        case 3:
            while (start < end){
                int middle = (start + end)/2;

                if(strncmp(client[middle]->codePostal ,search, strlen(search)) == 0){
                    showFilter(client,choix,middle,search);

                    return;
                }
                else if(strncmp(client[middle]->codePostal ,search, strlen(search))< 0){
                    start = middle + 1;
                }
                else if(strncmp(client[middle]->codePostal ,search, strlen(search))> 0){
                    end = middle;
                }

            }
            break;
        case 4:
            while (start < end){
                int middle = (start + end)/2;

                if(strncmp(client[middle]->metier ,search, strlen(search)) == 0){
                    showFilter(client,choix,middle,search);

                    return;
                }
                else if(strncmp(client[middle]->metier ,search, strlen(search))< 0){
                    start = middle + 1;
                }
                else if(strncmp(client[middle]->metier ,search, strlen(search))> 0){
                    end = middle;
                }

            }
            break;
        default:
            return;
    }



    printf("aucun r\202sultat");
}

void showFilter(CLIENT *client[], int choix,int middle, char *search){

    switch (choix) {
        case 1:
            while(strncmp(client[middle]->nom ,search, strlen(search))==0){ //retourne en arrière jusqu'a trouver un client ne
                middle--;                                                   //remplissant pas la condition car recherche ne trouve pas
                                                                            //forcement le premier mot concerné
            }
            middle++;                           // incrémentation de 1 pour éviter de montrer le client non concerné

            while (strncmp(client[middle]->nom ,search, strlen(search))==0){    //montre tout les clients concerné par le filtre
                printf(" %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                       client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                middle++;
            }
            break;

        case 2:
            while(strncmp(client[middle]->prenom ,search, strlen(search))==0){
                middle--;
            }
            middle++;
            while (strncmp(client[middle]->prenom ,search, strlen(search))==0){
                printf(" %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                       client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                middle++;
            }
            break;
        case 3:
            while(strncmp(client[middle]->codePostal ,search, strlen(search))==0){
                middle--;
            }
            middle++;
            while (strncmp(client[middle]->codePostal ,search, strlen(search))==0){
                printf(" %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                       client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                middle++;
            }
            break;
        case 4:
            while(strncmp(client[middle]->metier ,search, strlen(search))==0){
                middle--;
            }
            middle++;
            while (strncmp(client[middle]->metier ,search, strlen(search))==0){
                printf(" %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[middle]->prenom, client[middle]->nom,
                       client[middle]->ville,client[middle]->codePostal, client[middle]->telephone, client[middle]->email, client[middle]->metier);
                middle++;
            }
            break;
        default:
            return;

    }

}
