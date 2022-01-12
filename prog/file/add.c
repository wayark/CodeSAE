#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addClient(CLIENT *client[], int *ligne){//Mateo Guenot

    client[*ligne] = (CLIENT *) malloc(sizeof(CLIENT)); //aloue une nouvelle case dans la mémoire au rang 5001(*ligne)
                                                            // car le tableau va de 0 a 5000
    char prenom[20], nom[30], ville[20], codePostal[10], telephone[15], email[50], metier[30];
    printf("Si vous ne connaissez pas l'information metter : '.'\n");

    do
    {
        printf("Entrer le pr\202nom :");
        scanf("%s",prenom);
    } while(strlen(prenom)>20);
    if(prenom[0] == '.'){
        client[*ligne]->prenom[0] = '\0';
    }
    else{
        sscanf(prenom,"%s",client[*ligne]->prenom);
    }
    do
    {
        printf("Entrer le nom :");
        scanf("%s",nom);
    } while(strlen(nom)>30);
    if(nom[0] == '.')
        client[*ligne]->nom[0] = '\0';
    else{
        sscanf(nom,"%s",client[*ligne]->nom);
    }
    do
    {
        printf("Entrer la ville :");
        scanf("%s",ville);
    } while(strlen(ville)>20);
    if(ville[0] == '.')
        client[*ligne]->ville[0] = '\0';
    else{
    sscanf(ville,"%s",client[*ligne]->ville);
    }
    do
    {
        printf("Entrer le code postal (5 chiffres) :");
        scanf("%s",codePostal);
    } while((strlen(codePostal)!=5) && (codePostal[0] != '.') );
    if(codePostal[0] == '.')
        client[*ligne]->codePostal[0] = '\0';
    else{
        sscanf(codePostal,"%s",client[*ligne]->codePostal);
    }
    do
    {
        printf("Entrer le telephone sous la forme : 06.00.00.00.00 :");
        scanf("%s",telephone);
    } while((strlen(telephone)!=14 || (telephone[2]!='.') || (telephone[5]!='.') || (telephone[8]!='.') || (telephone[11]!='.')) && (telephone[0] != '.') );
    if(telephone[0] == '.')
        client[*ligne]->telephone[0] = '\0';
    else{
        sscanf(telephone,"%s",client[*ligne]->telephone);
    }


    do
    {
        printf("Entrer l'email :");
        scanf("%s",email);
    } while(strlen(email)>50);
    if(email[0] == '.')
        client[*ligne]->email[0] = '\0';
    else{
        sscanf(email,"%s",client[*ligne]->email);
    }
    do
    {
        printf("Entrer le m\202tier :");
        scanf("%s",metier);
    } while(strlen(metier)>30);
    if(metier[0] == '.')
        client[*ligne]->metier[0] = '\0';
    else{
        sscanf(metier,"%s",client[*ligne]->metier);
    }
    *ligne = *ligne + 1; //augmente la variable ligne car utiliser pour afficher le tableau
                            //permet d'afficher la case en plus

    //il faut trouver un moyen de mettre un mot dans la case avec des contrainte
    //ex: mettre que des chiffre dans la case code postal ou rentrer un mot pas trop long
    //scanf peut déborder si on met trop de lettre dans prenom et aller dans la case nom

}
