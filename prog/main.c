#include <stdio.h>
#include "client.h"




int main(){
<<<<<<< Updated upstream
    CLIENT *client;
    client = loadClient(client);
=======
    CLIENT *client = NULL ;
    loadClient(client);
    printf("%s", client->email);
>>>>>>> Stashed changes
    int choix;
    printf("=== Menu ===\n"
           "1. Ajouter des clients\n"
           "2. Modifier les donn\202es d'un client\n"
           "3. Supprimer des clients\n"
           "4. Affichage de la liste de tous les clients\n"
           "5. Filtre pour recherche\n"
           "6. Recherche d'un client\n"
           "7. Affichage des clients avec donn\202es manquantes\n");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1:
            printf("");
            break;
        case 2:
            printf("");
            break;
        case 3:
            printf("");
            break;
        case 4:
            showClient(client);
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
        default:
            printf("Veuillez renter un nombre correcte");
            break;
    }



}
