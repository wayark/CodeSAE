#include "modifier.h"
#include "search.h"
#include "trier.h"
#include <stdio.h>
#include <string.h>

void modifierClient(CLIENT *client[],int *ligne)//Mateo Guenot
{
    int ligne_client;
    int choix = 0;
    printf("Pour modifier les donn\202es d'un client veuillez rentrer le chiffre d'un des champs que vous possedez :\n"
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
        ModifierLaLigne(client,ligne_client);
        showAll(client,ligne);
        printf("\n\n  %-25s | %-25s | %-15s | %-6s | %-16s | %-38s | %-20s \n", client[ligne_client]->prenom, client[ligne_client]->nom,
               client[ligne_client]->ville,client[ligne_client]->codePostal, client[ligne_client]->telephone, client[ligne_client]->email, client[ligne_client]->metier);

    }
    else
    {
        printf("Veuillez rentrer un chiffre correcte !\n");
    }
}

void ModifierLaLigne(CLIENT *client[], int no_ligne)//Mateo Guenot
{
    int choix;
    char new_prenom[20], new_nom[30], new_ville[20], new_codePostal[10], new_telephone[15], new_email[50], new_metier[30];
    do
    {
        do
        {
            printf("\nQue voulez-vous modifier (entrer le chiffre) :\n"
                   "=========\n"
                   "1. Pr\202nom\n"
                   "2. Nom\n"
                   "3. Ville\n"
                   "4. Code Postal\n"
                   "5. T\202l\202phone\n"
                   "6. Email\n"
                   "7. M\202tier\n"
                   "=========\n"
                   "8. Sauvegarder et quitter.\n");
            scanf("%d",&choix);
        } while(choix > 8);
        switch (choix)
        {
            case 1:
                do
                {
                    printf("Entrer le nouveau pr\202nom (20 caractreres) :");
                    scanf("%s",new_prenom);
                } while(strlen(new_prenom)>20);
                strcpy(client[no_ligne]->prenom,new_prenom);
                break;
            case 2:
                do
                {
                    printf("Entrer le nouveau nom (30 caractreres) :");
                    scanf("%s",new_nom);
                } while(strlen(new_nom)>30);
                strcpy(client[no_ligne]->nom,new_nom);
                break;
            case 3:
                do
                {
                    printf("Entrer le nouveau ville (20 caractreres) :");
                    scanf("%s",new_ville);
                } while(strlen(new_ville)>20);
                strcpy(client[no_ligne]->ville,new_ville);
                break;
            case 4:
                do
                {
                    printf("Entrer le nouveau Code Postal (5 chiffres) :");
                    scanf("%s",new_codePostal);
                } while (strlen(new_codePostal)>5);
                strcpy(client[no_ligne]->codePostal,new_codePostal);
                break;
            case 5:
                do
                {
                    printf("Entrer le nouveau t\202l\202phone (10 chiffres) a \202crire 00.00.00.00.00 :");
                    scanf("%s",new_telephone);
                } while (strlen(new_telephone)>14);
                strcpy(client[no_ligne]->telephone,new_telephone);
                break;
            case 6:
                do
                {
                    printf("Entrer le nouveau email (50 caractreres) :");
                    scanf("%s",new_email);
                } while (strlen(new_email)>50);
                strcpy(client[no_ligne]->email,new_email);
                break;
            case 7:
                do
                {
                    printf("Entrer le nouveau m\202tier (30 caractreres) :");
                    scanf("%s",new_metier);
                } while(strlen(new_metier)>30);
                strcpy(client[no_ligne]->metier,new_metier);
                break;
            case 8:
                printf("\nVous avez bien sauvegarder !\n");
                break;
            default:
                printf("Erreur !");
        }
    } while(choix != 8);
}

