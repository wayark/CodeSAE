#include "blank.h"
#include <stdio.h>

void blankClient(CLIENT *client[], int taille){
    int i=0;
    int compt = 0;
    while (i < taille-1){   //tant que ce n'est pas la fin du tableau
        if(client[i]->prenom[0]=='\0'|| client[i]->nom[0]=='\0' || client[i]->ville[0]=='\0'|| client[i]->codePostal[0]=='\0'||
                client[i]->telephone[0]=='\0'|| client[i]->email[0]=='\0'|| client[i]->metier[0]=='\0'){


            printf(" %-25s | %-25s | %-15s | %-11s | %-16s | %-38s | %-20s \n", client[i]->prenom, client[i]->nom,
                   client[i]->ville,client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier);
            compt++;

        }
        i++;
    }
    printf("\n\nnombre de client avec un champ vide : %d \n",compt);
}
