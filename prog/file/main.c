#include <stdio.h>
#include "client.h"
#include "add.h"
#include "modifier.h"
#include "supprimer.h"
#include "save.h"


int main() {
    char sortie[200];
    int ligne = 0;

    FILE *fp = fopen(file, "r");
    while (fgets(sortie, sizeof(sortie), fp)!=NULL) {
        ligne++;
    }
    fclose(fp);


    CLIENT *client[ligne];


    loadClient(client);

    int choix;
    do {
        printf("\n\n=== Menu ===\n"
               "1. Affichage des clients\n"
               "2. Ajouter des clients\n"
               "3. Supprimer des clients\n"
               "4. Modifier les donn\202es d'un client\n"
               "5. Sauvegarder\n"
               "6. Quitter\n\n");


        scanf("%d", &choix);
        switch (choix) {
            case 1:
                showClient(client, &ligne);
                break;
            case 2:
                addClient(client,&ligne);
                showAll(client,&ligne);
                break;
            case 3:
                supprimer(client,&ligne);
                break;
            case 4:
                modifierClient(client,&ligne);
                break;
            case 5:
                saveFile(client, &ligne);
                break;
            case 6:
                break;
            default:
                printf("Veuillez renter un nombre correcte");
                break;
        }
    } while (choix < 6);

    return 0;


}
