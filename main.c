#include <stdio.h>
#include <stdlib.h>
#include "include/carnet.h"

int main(int argc, char const *argv[])
{
    FILE *FIC;
    int choix = 0;
    Carnet book;
    init_carnet(&book);
    P p;
    char *nom,*num;
    nom = (char *)malloc(sizeof(char));
    num = (char *)malloc(sizeof(char));
    /**
     * Restaurer les donnees sauvegardes dans le carnet
    */
    restaure_data(FIC,&book);
    do
    {
        printf("/****************************************************/\n\tBienvenue dans votre carnet electronique\n/****************************************************/\n");
        printf("\tVeuiller choisir une option\n");
        printf("\t1-Ajouter une personne au carnet\n");
        printf("\t2-Afficher le carnet\n");
        printf("\t3-Quitter le programme\n");
        scanf("%d",&choix);
        switch (choix)
        {
            case 1:{
                printf("Entrer le nom et le numero du contact a enregistrer\n");
                scanf("%s %s",nom,num);
                p = create_person(nom,num,p);
                //print_person(*p);
                add_person(&book,p);
                printf("Enregistrement reussi\n");
                break;
            }
            case 2:{
                if (book.compteur == 0){
                    goto label;
                }else{
                    Tri_Alpha(&book);
                }
                label:
                print_carnet(book);
                /* printf("Book print\n"); */
                break;
            }
            case 3:
                save_data(FIC,book);
                printf("Donnees sauvegardees...\n");
                exit(0);
        
            default:
                break;
        }
    } while (choix != 3);
        free(nom);
        free(num);
        free(p);

    return 0;
}