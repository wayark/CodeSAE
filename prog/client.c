#include <stdio.h>
#include <stdlib.h>
#include "client.h"

void showClient(CLIENT *client ){

    FILE *fp = fopen("\\Users\\liaml\\Desktop\\cours\\sae\\1-2 algo et c\\annuaire5000.csv","r");

    if (!fp) {
        printf("le fchier est invalide");
        exit(EXIT_FAILURE);
    }

    char sortie[100];
    int i;
    int compt;
    int mot;
    while(fgets(sortie, sizeof(sortie), fp)) {
        client = (CLIENT*)malloc(sizeof (CLIENT));
        compt = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {
            while (sortie[i] == ',') {
                if (compt == 0) {
                    client->prenom[mot] = '\0';
                }
                else if (compt == 1) {
                    client->nom[mot] = '\0';
                }
                else if (compt == 2) {
                    client->ville[mot] = '\0';
                }
                else if (compt == 3) {
                    client->codePostal[mot] = '\0';
                }
                else if (compt == 4) {
                    client->telephone[mot] = '\0';
                }
                else if (compt == 5) {
                    client->email[mot] = '\0';
                }
                compt++;
                mot = 0;
                i++;

            }
            if (compt == 0) {
                client->prenom[mot] = sortie[i];
            }
            else if (compt == 1) {
                client->nom[mot] = sortie[i];
            }
            else if (compt == 2) {
                client->ville[mot] = sortie[i];
            }
            else if (compt == 3) {
                client->codePostal[mot] = sortie[i];
            }
            else if (compt == 4) {
                client->telephone[mot] = sortie[i];
            }
            else if (compt == 5) {
                client->email[mot] = sortie[i];
            }
            else if (compt == 6) {
                client->metier[mot] = sortie[i];
            }

            mot++;
        }
        client->metier[mot] = '\0';
        printf(" %s | %s | %s | %s | %s | %s | %s  \n", client->prenom, client->nom, client->ville, client->codePostal, client->telephone,
               client->email, client->metier);
        client = client->suivant;

    }
}
