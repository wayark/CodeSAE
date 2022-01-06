#include "add.h"
#include "trier.h"
#include "search.h"
#include <stdio.h>

void supprimer(CLIENT *client[], int *ligne)//Mateo Guenot
{
    int i, ligne_client, choix;
    printf("Pour supprimer les donn\202es d'un client veuillez rentrer le chiffre d'un des champs que vous possedez :\n"
           "1. Nom\n"
           "2. Pr\202nom\n"
           "3. T\202l\202phone\n"
           "4. Email\n\n");
    scanf("%d",&choix);
    if(choix<=4)
    {
        trie(client,choix,0,*ligne -1);
        ligne_client = search(client,choix,ligne);
        if(ligne_client == -1)
        {
            printf("Erreur !");
            return;
        }
        for(i = ligne_client; i < *ligne - 1 ;i++)
        {
            client[i] = client[i + 1];
        }
        showAll(client,ligne);
    }
    else
    {
        printf("Veuillez rentrer un chiffre correcte !\n");
    }
}