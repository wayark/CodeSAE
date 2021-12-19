#include <stdio.h>
#include "client.h"


int main() {
    char sortie[200];
    int ligne = 0;

    FILE *fp = fopen(file, "r");
    while (fgets(sortie, sizeof(sortie), fp)!=NULL) {
        ligne++;
    }
    fclose(fp);
    CLIENT *client[ligne];
    loadClient(client, &ligne);


    int choix;
    do {
        printf("=== Menu ===\n"
               "1. Affichage des clients\n"
               "2. Ajouter des clients\n"
               "3. Supprimer des clients\n"
               "4. Modifier les donn\202es d'un client\n"
               "5. Quitter\n\n");


        scanf("%d", &choix);
        switch (choix) {
            case 1:
                showClient(client, &ligne);
                break;
            case 2:
                printf("");
                break;
            case 3:
                printf("");
                break;
            case 4:
                printf("");
                break;
            case 5:
                break;
            default:
                printf("Veuillez renter un nombre correcte");
                break;
        }
    } while (choix != 5);

    return 0;


}
