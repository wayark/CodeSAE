#include "save.h"
#include <stdio.h>
#include <stdlib.h>

void saveFile(CLIENT *client[], int *ligne, char chemin[]){//Benjamin Bonnepart---fonction de sauvegarde de structure

    FILE *fp = fopen(chemin,"w"); //Ouvre le fichier csv qui a été ouvert au départ
    int i;
    for (i = 0; i < *ligne; i++) { // Vas du client 0 au client maximal

        fprintf(fp,"%s,%s,%s,%s,%s,%s,%s", client[i]->prenom, client[i]->nom,
               client[i]->ville,
               client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier); //Ecrit sur le dossier le client de la ligne i

    }
    fclose(fp);
}

