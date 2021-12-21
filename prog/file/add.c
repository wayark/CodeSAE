#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addClient(CLIENT *client[], int *ligne){

    client[*ligne] = (CLIENT *) malloc(sizeof(CLIENT)); //aloue une nouvelle case dans la mémoire au rang 5001(*ligne)
                                                            // car le tableau va de 0 a 5000
    char prenom[20], nom[30], ville[20], codePostal[10], telephone[15], email[50], metier[30];
    printf("Si vous ne connaissez pas l'information metter : '.'\n");

    do
    {
        printf("Entrer le pr\202nom :");
        scanf("%s",prenom);
    } while(strlen(prenom)>21);
    if(prenom[0] == '.')
        prenom[0] = ' ';
    sscanf(prenom,"%s",client[*ligne]->prenom); //met mot taper dans la case associer

    do
    {
        printf("Entrer le nom :");
        scanf("%s",nom);
    } while(strlen(nom)>31);
    if(nom[0] == '.')
        nom[0] = ' ';
    sscanf(nom,"%s",client[*ligne]->nom);

    do
    {
        printf("Entrer la ville :");
        scanf("%s",ville);
    } while(strlen(ville)>21);
    if(ville[0] == '.')
        ville[0] = ' ';
    sscanf(ville,"%s",client[*ligne]->ville);

    do
    {
        printf("Entrer le code postal (5 chiffres) :");
        scanf("%s",codePostal);
    } while((strlen(codePostal)!=5) && (codePostal[0] != '.'));
    if(codePostal[0] == '.')
        codePostal[0] = ' ';
    sscanf(codePostal,"%s",client[*ligne]->codePostal);

    do
    {
        printf("Entrer le telephone sous la forme : 06.00.00.00.00 :");
        scanf("%s",telephone);
    } while(strlen(telephone)!=14 && (telephone[0] != '.'));
    if(telephone[0] == '.')
        telephone[0] = ' ';
    sscanf(telephone,"%s",client[*ligne]->telephone);

    do
    {
        printf("Entrer l'email :");
        scanf("%s",email);
    } while(strlen(email)>51);
    if(email[0] == '.')
        email[0] = ' ';
    sscanf(email,"%s",client[*ligne]->email);

    do
    {
        printf("Entrer le m\202tier :");
        scanf("%s",metier);
    } while(strlen(metier)>31);
    if(metier[0] == '.')
        metier[0] = ' ';
    sscanf(metier,"%s",client[*ligne]->metier);

    *ligne = *ligne + 1; //augmente la variable ligne car utiliser pour afficher le tableau
                            //permet d'afficher la case en plus

    //il faut trouver un moyen de mettre un mot dans la case avec des contrainte
    //ex: mettre que des chiffre dans la case code postal ou rentrer un mot pas trop long
    //scanf peut déborder si on met trop de lettre dans prenom et aller dans la case nom

}
