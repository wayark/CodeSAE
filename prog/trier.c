#include "trier.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Trier(CLIENT *client[], int choix, int droite, int gauche){
    int i,j,pivot;
    srand();

}

void Swap(CLIENT *client[], int pos1, int pos2){
        CLIENT *temp;
        temp = client[pos1];
        client[pos1] = client[pos2];
        client[pos2] = temp;
}