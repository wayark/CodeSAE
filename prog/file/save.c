#include "save.h"
#include <stdio.h>
#include <stdlib.h>

void saveFile(CLIENT *client[], int *ligne){

    FILE *fp = fopen("save.txt","w");
    int i;
    for (i = 0; i < *ligne; i++) {

        fprintf(fp,"%d  %-25s | %-25s | %-15s | %-11s | %-16s | %-38s | %-20s \n\n",i, client[i]->prenom, client[i]->nom,
               client[i]->ville,
               client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier);

    }
    fclose(fp);
}

