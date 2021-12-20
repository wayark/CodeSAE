#include "client.h"

#ifndef PROG_FILTER_H
#define PROG_FILTER_H

void filter(CLIENT *client[],int choix,int taille);
void showFilter(CLIENT *client[],int choix, int middle, char *search);
#endif //PROG_FILTER_H
