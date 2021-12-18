

#ifndef PROG_CLIENT_H
#define PROG_CLIENT_H

typedef struct Client{
    char prenom[20] ;
    char nom[30];
    char ville[20];
    char codePostal[10];
    char telephone[15];
    char email[50];
    char metier[50];
}CLIENT;

void loadClient(CLIENT *client[],int *ligne);
void showClient(CLIENT *client[],int *ligne);
void showAll(CLIENT *client[],int *ligne);
void Filter(CLIENT *client[], int choix);


#endif //PROG_CLIENT_H
