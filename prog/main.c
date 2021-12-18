#include <stdio.h>
#include "client.h"


int main() {
    char sortie[100];
    int ligne = 0;

    FILE *fp = fopen("petitExemple.csv", "r");
    while (fgets(sortie, sizeof(sortie), fp)) {
        ligne++;
    }
    fclose(fp);
    CLIENT *client[ligne];
    loadClient(client, &ligne);


    int choix;
    do {
        printf("=== Menu ===\n"
               "1. Affichage de la liste de tous les clients\n"
               "2. Ajouter des clients\n"
               "3. Supprimer des clients\n"
               "4. Modifier les donn\202es d'un client\n"
               "5. Filtre pour recherche\n"
               "6. Recherche d'un client\n"
               "7. Affichage des clients avec donn\202es manquantes\n"
               "8. Quitter\n\n");


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
                printf("");
                break;
            case 6:
                printf("");
                break;
            case 7:
                printf("");
                break;
            case 8:
                break;
            default:
                printf("Veuillez renter un nombre correcte");
                break;
        }
    } while (choix != 8);

    return 0;


}
