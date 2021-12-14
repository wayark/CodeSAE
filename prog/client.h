

#ifndef PROG_CLIENT_H
#define PROG_CLIENT_H

typedef struct Client{
    char prenom[20] ;
    char nom[30];
    char ville[20];
    char telephone[15];
    char email[50];
    char metier[50];
    char codePostal[5];
    struct Client *suivant;
}CLIENT;

CLIENT *loadClient(CLIENT *Client);
void showClient(CLIENT *Client);


#endif //PROG_CLIENT_H
