#include "blank.h"
#include <stdio.h>

void blankClient(CLIENT *client[], int taille){//Benjamin Bonnepart---fonction de detection de client ayant une case vide
    int i=0;
    int compt = 0;
    while (i < taille-1){   //tant que ce n'est pas la fin du tableau
        if(client[i]->prenom[0]=='\0'|| client[i]->nom[0]=='\0' || client[i]->ville[0]=='\0'|| client[i]->codePostal[0]=='\0'||
                client[i]->telephone[0]=='\0'|| client[i]->email[0]=='\0'|| client[i]->metier[0]=='\0'){ // si un de ces champs ou plusieur est vide


            printf("%d %-25s | %-25s | %-15s | %-11s | %-16s | %-38s | %-20s \n",i, client[i]->prenom, client[i]->nom,
                   client[i]->ville,client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier); // alors affiche la ligne du client
            compt++;

        }
        i++;
    }
    printf("\n\nNombre de client avec un champ vide : %d \n",compt);
}
