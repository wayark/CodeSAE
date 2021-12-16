#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"


CLIENT *loadClient(CLIENT *client) {

    int i, mot, champ;
    int j = 0;
    int ligne = 0;
    char sortie[250];

    FILE *fp = fopen("annuaire5000.csv", "r");

    while (fgets(sortie, sizeof(sortie), fp)) {
        ligne++;
    }
    fseek(fp, 0, SEEK_SET);

    client = (CLIENT *) malloc(ligne * sizeof(CLIENT));

    while (fgets(sortie, sizeof(sortie), fp)) {
        champ = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {
            while (sortie[i] == ',') {
                if (champ == 0) {
                    (client + j)->prenom[mot] = '\0';
                } else if (champ == 1) {
                    (client + j)->nom[mot] = '\0';
                } else if (champ == 2) {
                    (client + j)->ville[mot] = '\0';
                } else if (champ == 3) {
                    (client + j)->codePostal[mot] = '\0';
                } else if (champ == 4) {
                    (client + j)->telephone[mot] = '\0';
                } else if (champ == 5) {
                    (client + j)->email[mot] = '\0';
                }
                champ++;
                mot = 0;
                i++;

            }
            if (champ == 0) {
                (client + j)->prenom[mot] = sortie[i];
            } else if (champ == 1) {
                (client + j)->nom[mot] = sortie[i];
            } else if (champ == 2) {
                (client + j)->ville[mot] = sortie[i];
            } else if (champ == 3) {
                (client + j)->codePostal[mot] = sortie[i];
            } else if (champ == 4) {
                (client + j)->telephone[mot] = sortie[i];
            } else if (champ == 5) {
                (client + j)->email[mot] = sortie[i];
            } else if (champ == 6) {
                (client + j)->metier[mot] = sortie[i];
            }
            mot++;

        }
        j++;
    }
    fclose(fp);
    return (client);
}


void showClient(CLIENT *client) {
    int choix;
    printf("===faire une recherche===\n"
           "1. rechercher clients\n"
           "2. filtrer clients\n"
           "3. montrer tout les clients\n"
           "4. montrer les clients avec des champs manquants\n"
           "5. retourner en arri\202re\n\n");


    do {
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                Filter(client);
                break;
            case 2:

                break;
            case 3:
                showAll(client);
                break;
            case 4:

                break;
            case 5:
                break;
            default:
                printf("veuillez rentrer un nombre valide");
                break;

        }
    } while (choix != 5);


}

void showAll(CLIENT *client) {
    int i;
    for (i = 0; i < 5001; i++) {

        printf(" %-15s | %-15s | %-10s | %-6s | %-16s | %-30s | %-20s \n", (client + i)->prenom, (client + i)->nom,
               (client + i)->ville,
               (client + i)->codePostal, (client + i)->telephone, (client + i)->email, (client + i)->metier);

    }
}

void Filter(CLIENT *client){

}