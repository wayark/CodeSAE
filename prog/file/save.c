#include "save.h"
#include <stdio.h>
#include <stdlib.h>

void saveFile(CLIENT *client[], int *ligne){//Benjamin Bonnepart---fonction de sauvegarde de structure

    FILE *fp = fopen("save.txt","w"); //Ouvre le fichier save.txt si il n'existe pas il le crée si il existe il écris part dessus
    int i;
    for (i = 0; i < *ligne; i++) { // Vas du client 0 au client maximal

        fprintf(fp,"%d  %-25s | %-25s | %-15s | %-11s | %-16s | %-38s | %-20s \n\n",i, client[i]->prenom, client[i]->nom,
               client[i]->ville,
               client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier); //Affiche le client de la ligne i

    }
    fclose(fp);
}

