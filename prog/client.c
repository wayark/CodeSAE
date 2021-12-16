#include <stdio.h>
#include <stdlib.h>
#include "client.h"


<<<<<<< Updated upstream
CLIENT *loadClient(CLIENT *client){

    int i,mot,champ;
    int j = 0;
    char sortie[250];

    FILE *fp = fopen("annuaire5000.csv", "r");

    client = (CLIENT *) malloc(5100 * sizeof(CLIENT));
=======
CLIENT *loadClient(CLIENT *client) {
    CLIENT *save;
    FILE *fp = fopen(file, "r");
>>>>>>> Stashed changes


<<<<<<< Updated upstream
    while(fgets(sortie, sizeof(sortie), fp)) {
        champ = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {
            while (sortie[i] == ',') {
                if (champ == 0) {
                    (client+j)->prenom[mot+1] = '\0';
                } else if (champ == 1) {
                    (client+j)->nom[mot+1] = '\0';
                } else if (champ == 2) {
                    (client+j)->ville[mot+1] = '\0';
                } else if (champ == 3) {
                    (client+j)->codePostal[mot+1] = '\0';
                } else if (champ == 4) {
                    (client+j)->telephone[mot+1] = '\0';
                } else if (champ == 5) {
                    (client+j)->email[mot+1] = '\0';
                }
                champ++;
=======
    char sortie[250];
    int i;
    int compt;
    int mot;
    while (fgets(sortie, sizeof(sortie), fp)) {
        client = (CLIENT *) malloc(sizeof(CLIENT));
        compt = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {
            while (sortie[i] == ',') {
                if (compt == 0) {
                    client->prenom[mot] = '\0';
                } else if (compt == 1) {
                    client->nom[mot] = '\0';
                } else if (compt == 2) {
                    client->ville[mot] = '\0';
                } else if (compt == 3) {
                    client->codePostal[mot] = '\0';
                } else if (compt == 4) {
                    client->telephone[mot] = '\0';
                } else if (compt == 5) {
                    client->email[mot] = '\0';
                }
                compt++;
>>>>>>> Stashed changes
                mot = 0;
                i++;

            }
<<<<<<< Updated upstream
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
=======
            if (compt == 0) {
                client->prenom[mot] = sortie[i];
            } else if (compt == 1) {
                client->nom[mot] = sortie[i];
            } else if (compt == 2) {
                client->ville[mot] = sortie[i];
            } else if (compt == 3) {
                client->codePostal[mot] = sortie[i];
            } else if (compt == 4) {
                client->telephone[mot] = sortie[i];
            } else if (compt == 5) {
                client->email[mot] = sortie[i];
            } else if (compt == 6) {
                client->metier[mot] = sortie[i];
            }

            mot++;
        }
        client->metier[mot - 1] = '\0';
        printf(" %s | %s | %s | %s | %s | %s | %s |\n", client->prenom, client->nom, client->ville,
               client->codePostal,client->telephone, client->email, client->metier);
        client = client->suivant;
>>>>>>> Stashed changes

        }
        j++;
    }
    fclose(fp);
<<<<<<< Updated upstream
    return (client);
}

void showClient(CLIENT *client){
int i;
    for (i = 0; i < 5001; i++) {

        printf(" %-20s | %-20s | %-10s | %-6s | %-20s | %-30s | %-20s \n", (client + i)->prenom, (client + i)->nom, (client + i)->ville,
               (client + i)->codePostal,(client + i)->telephone, (client + i)->email, (client + i)->metier);

    }
=======
    return (save);
}

void showClient(CLIENT *client) {

>>>>>>> Stashed changes
}
