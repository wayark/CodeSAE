#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "trier.h"


void loadClient(CLIENT *client[], int *ligne) {

    int i, mot, champ;
    int j = 0;
    char sortie[250];

    FILE *fp = fopen(file, "r");
    fseek(fp,0,SEEK_SET);

    while (fgets(sortie, sizeof(sortie), fp)) {
        client[j] = (CLIENT *) malloc(sizeof(CLIENT));
        champ = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {


            while (sortie[i] == ',') {
                if (champ == 0) {
                    client[j]->prenom[mot] = '\0';
                } else if (champ == 1) {
                    client[j]->nom[mot] = '\0';
                } else if (champ == 2) {
                    client[j]->ville[mot] = '\0';
                } else if (champ == 3) {
                    client[j]->codePostal[mot] = '\0';
                } else if (champ == 4) {
                    client[j]->telephone[mot] = '\0';
                } else if (champ == 5) {
                    client[j]->email[mot] = '\0';
                }
                champ++;
                mot = 0;
                i++;

            }
            if (champ == 0) {
                client[j]->prenom[mot] = sortie[i];
            } else if (champ == 1) {
                client[j]->nom[mot] = sortie[i];
            } else if (champ == 2) {
                client[j]->ville[mot] = sortie[i];
            } else if (champ == 3) {
                client[j]->codePostal[mot] = sortie[i];
            } else if (champ == 4) {
                client[j]->telephone[mot] = sortie[i];
            } else if (champ == 5) {
                client[j]->email[mot] = sortie[i];
            } else if (champ == 6) {
                client[j]->metier[mot] = sortie[i];
            }
            mot++;

        }
        client[j]->metier[mot] = '\0';
        j++;
    }
    fclose(fp);
}


void showClient(CLIENT *client[], int *ligne) {
    int choix,option;

    do {
        printf("\n\n===faire une recherche===\n"
               "1. trier liste\n"
               "2. rechercher clients\n"
               "3. filtrer clients\n"
               "4. montrer tout les clients\n"
               "5. montrer les clients avec des champs manquants\n"
               "6. retourner en arriere\n\n");


        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("    ===trier par===\n"
                       "    1. nom\n"
                       "    2. pr\202nom\n"
                       "    3. code postal\n"
                       "    4. profession\n");
                scanf("%d",&option);
                if(option > 4){
                    printf("valeur incorrecte");
                    break;
                }
                trie(client,option,0,*ligne-2);
                showAll(client,ligne);
                break;



                
            case 2:
                printf("    ===rechercher par===\n"
                       "    1. nom\n"
                       "    2. pr\202nom\n"
                       "    3. t\202l\202phone\n"
                       "    4. email\n");
                scanf("%d",&option);
                break;


            case 3:

                break;
            case 4:
                showAll(client, ligne);
                break;
            case 5:

                break;
            case 6:
                break;
            default:
                printf("veuillez rentrer un nombre valide");
                break;

        }
    } while (choix != 6);


}

void showAll(CLIENT *client[], int *ligne) {
    int i;
    for (i = 0; i < *ligne - 1; i++) {

        printf("%d    %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n",i, client[i]->prenom, client[i]->nom,
               client[i]->ville,
               client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier);

    }
}
