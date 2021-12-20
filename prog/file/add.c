#include "add.h"
#include <stdio.h>
#include <stdlib.h>

void addClient(CLIENT *client[], int *ligne){

    client[*ligne] = (CLIENT *) malloc(sizeof(CLIENT));

    printf("donner un prenom :");
    scanf("%20s",client[*ligne]->prenom);
    


    *ligne = *ligne + 1;



}
