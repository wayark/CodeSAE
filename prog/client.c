#include <stdio.h>
#include <stdlib.h>
#include "client.h"


CLIENT *loadClient(CLIENT *client){

    int i,mot,champ;
    int j = 0;
    char sortie[250];

    FILE *fp = fopen("annuaire5000.csv", "r");

    client = (CLIENT *) malloc(5100 * sizeof(CLIENT));

    while(fgets(sortie, sizeof(sortie), fp)) {
        champ = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {
            while (sortie[i] == ',') {
                if (champ == 0) {
                    (client+j)->prenom[mot] = '\0';
                } else if (champ == 1) {
                    (client+j)->nom[mot] = '\0';
                } else if (champ == 2) {
                    (client+j)->ville[mot] = '\0';
                } else if (champ == 3) {
                    (client+j)->codePostal[mot] = '\0';
                } else if (champ == 4) {
                    (client+j)->telephone[mot] = '\0';
                } else if (champ == 5) {
                    (client+j)->email[mot] = '\0';
                }
                champ++;
                mot = 0;
                i++;

            }
            if (champ == 0) {
                (client+j)->prenom[mot] = sortie[i];
            } else if (champ == 1) {
                (client+j)->nom[mot] = sortie[i];
            } else if (champ == 2) {
                (client+j)->ville[mot] = sortie[i];
            } else if (champ == 3) {
                (client+j)->codePostal[mot] = sortie[i];
            } else if (champ == 4) {
                (client+j)->telephone[mot] = sortie[i];
            } else if (champ == 5) {
                (client+j)->email[mot] = sortie[i];
            } else if (champ == 6) {
                (client+j)->metier[mot] = sortie[i];
            }
            mot++;

        }
        j++;
    }
    fclose(fp);
    return (client);
}

void showClient(CLIENT *client){
int i;
    for (i = 0; i < 5001; i++) {

        printf(" %-15s | %-20s | %-10s | %-6s | %-20s | %-30s | %-20s \n", (client + i)->prenom, (client + i)->nom, (client + i)->ville,
               (client + i)->codePostal,(client + i)->telephone, (client + i)->email, (client + i)->metier);

    }

}

