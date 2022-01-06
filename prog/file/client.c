#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "client.h"
#include "trier.h"
#include "filter.h"
#include "search.h"
#include "blank.h"


void loadClient(CLIENT *client[], char chemin[]) {//Liam Lucas--- fonction de chargement et du découpage du fichier

    int i, mot, champ;
    int j = 0;
    char sortie[250];

    FILE *fp = fopen(chemin, "r");//ouverture du dossier avec le chemin donnée par l'utilisateur
    fseek(fp,0,SEEK_SET);

    if (!fp){
        printf("fichier csv invalide");// si le dossier est invalide retourne une erreur
        exit(EXIT_FAILURE);
    }
                                                //tant que l'on peut lire une ligne dans notre dossier
    while (fgets(sortie, sizeof(sortie), fp)) { //+ la ligne lu est mis dans la variable sortie

        client[j] = (CLIENT *) malloc(sizeof(CLIENT));//pour chaque ligne on alloue une nouvelle case dans la structure
        champ = 0;
        mot = 0;
        for (i = 0; sortie[i] != '\0'; i++) {// tant que l'on est pas au bout de la ligne


            while (sortie[i] == ',') {//si on trouve une virgule
                if (champ == 0) {
                    client[j]->prenom[mot] = '\0';//on met un \0 a la fin de la chaine actuel
                } else if (champ == 1) {
                    client[j]->nom[mot] = '\0';
                } else if (champ == 2) {
                    client[j]->ville[mot] = '\0';
                } else if (champ == 3) {
                    client[j]->codePostal[mot] = '\0';
                } else if (champ == 4) {
                    client[j]->telephone[mot] = '\0';
                } else if (champ == 5) {
                    client[j]->email[mot] = '\0';
                }
                champ++;//passage au champs suivant de la structure
                mot = 0;//remise a 0 du compteur qui parcoure chaque champ
                i++;//passage a la lettre suivante de "sortie" pour ne pas prendre la virgule

            }
            if (champ == 0) {
                client[j]->prenom[mot] = sortie[i];//introduction du caractère sortie[i] dans le champs corrspondant
            } else if (champ == 1) {
                client[j]->nom[mot] = sortie[i];
            } else if (champ == 2) {
                client[j]->ville[mot] = sortie[i];
            } else if (champ == 3) {
                client[j]->codePostal[mot] = sortie[i];
            } else if (champ == 4) {
                client[j]->telephone[mot] = sortie[i];
            } else if (champ == 5) {
                client[j]->email[mot] = sortie[i];
            } else if (champ == 6) {
                client[j]->metier[mot] = sortie[i];
            }
            mot++;

        }
        client[j]->metier[mot] = '\0';
        j++;
    }
    fclose(fp);
}


void showClient(CLIENT *client[], int *ligne) {//Liam Lucas---- fonction de menu pour toute les fonctions d'affichage
    int choix,option;

    do {
        printf("\n\n===Faire une recherche===\n"
               "1. Trier liste\n"
               "2. Rechercher clients\n"
               "3. Filtrer clients\n"
               "4. Montrer tout les clients\n"
               "5. Montrer les clients avec des champs manquants\n"
               "6. Retourner en arriere\n\n");


        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("    ===trier par===\n"
                       "    1. Nom\n"
                       "    2. Pr\202nom\n"
                       "    3. Code postal\n"
                       "    4. Profession\n");
                scanf("%d",&option);
                if(option > 4|| option <1){
                    printf("Valeur incorrecte");
                    break;
                }
                clock_t start = clock();//calcule du temps d'execution

                trie(client,option,0,*ligne-1);
                clock_t stop = clock();
                double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                showAll(client,ligne);
                printf("Time elapsed in ms: %f", elapsed);



                break;


            case 2:
                printf("    ===rechercher par===\n"
                       "    1. Nom\n"
                       "    2. Pr\202nom\n"
                       "    3. T\202l\202phone\n"
                       "    4. Email\n");
                scanf("%d",&option);
                if(option > 4|| option <1){
                    printf("Valeur incorrecte");
                    break;
                }
                search(client,option,ligne);
                break;


            case 3:
                printf("    ===Filtrer par===\n"
                       "    1. Nom\n"
                       "    2. Pr\202nom\n"
                       "    3. Code postal\n"
                       "    4. Profession\n");
                scanf("%d",&option);
                if(option > 4 || option <1){
                    printf("Valeur incorrecte");
                    break;
                }
                filter(client,option,*ligne-1);
                break;



            case 4:
                showAll(client, ligne);
                break;

            case 5:
                blankClient(client,*ligne);
                break;


            case 6:
                break;
            default:
                printf("veuillez rentrer un nombre valide");
                break;

        }
    } while (choix != 6);


}

void showAll(CLIENT *client[], int *ligne) {//Liam Lucas---fonction d'affichage de ligne
    int i;
    printf(" %-25s | %-25s | %-15s | %-11s | %-16s | %-38s | %-20s \n","prenom","nom","ville","code postal","telephone","email","metier");
    printf("%-100s","============================================================================================================================================================\n");
    for (i = 0; i < *ligne; i++) {// i allant de 0 au nombre de ligne du fichier donnée

        printf("%d  %-25s | %-25s | %-15s | %-11s | %-16s | %-38s | %-20s \n\n",i, client[i]->prenom, client[i]->nom,
               client[i]->ville,
               client[i]->codePostal, client[i]->telephone, client[i]->email, client[i]->metier);

    }
}
