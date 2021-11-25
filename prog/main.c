#include <stdio.h>
#include <stdlib.h>


typedef struct Client{
    char prenom[20] ;
    char nom[20];
    char ville[20];
    char telephone[15];
    char email[40];
    char metier[20];
    char codePostal[5];
    struct client *suivant;
}CLIENT;



int main(){
    FILE *fp = fopen("\\Users\\liaml\\Desktop\\cours\\sae\\1-2 algo et c\\annuaire5000.csv","r");
    CLIENT *client = NULL ;

    if (!fp){
        printf("le fichier est invalide");
        return(EXIT_FAILURE);
    }

    char sortie[100];
    int i;
    int compt;
    int mot;
    while(fgets(sortie, sizeof (sortie), fp)) {
        client =malloc(sizeof (CLIENT));
        compt = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {
            while (sortie[i] == ',') {
                compt++;
                mot = 0;
                i++;

            }
            if (compt == 0) {
                client->prenom[mot] = sortie[i];
            }
            if (compt == 1) {
                client->nom[mot] = sortie[i];
            }
            if (compt == 2) {
                client->ville[mot] = sortie[i];
            }
            if (compt == 3) {
                client->codePostal[mot] = sortie[i];
            }
            if (compt == 4) {
                client->telephone[mot] = sortie[i];
            }
            if (compt == 5) {
                client->email[mot] = sortie[i];
            }
            if (compt == 6) {
                client->metier[mot] = sortie[i];
            }
            mot++;
        }

        printf(" %s | %s | %s | %s | %s | %s | %s  \n", client->prenom, client->nom, client->ville, client->codePostal, client->telephone,
               client->email, client->metier);
        client = client->suivant;
    }
    fclose(fp);
    return(EXIT_SUCCESS);
}
