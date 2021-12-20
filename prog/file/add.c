#include "add.h"
#include <stdio.h>
#include <stdlib.h>

void addClient(CLIENT *client[], int *ligne){

    client[*ligne] = (CLIENT *) malloc(sizeof(CLIENT)); //aloue une nouvelle case dans la mémoire au rang 5001(*ligne)
                                                        // car le tableau va de 0 a 5000

    printf("donner un prenom :");
    scanf("%20s",client[*ligne]->prenom);       //met mot taper dans la case associer

    *ligne = *ligne + 1; //augmente la variable ligne car utiliser pour afficher le tableau
                            //permet d'afficher la case en plus

    //il faut trouver un moyen de mettre un mot dans la case avec des contrainte
    //ex: mettre que des chiffre dans la case code postal ou rentrer un mot pas trop long
    //scanf peut déborder si on met trop de lettre dans prenom et aller dans la case nom

}
