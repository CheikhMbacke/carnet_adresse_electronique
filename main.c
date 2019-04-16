#include <stdio.h>
#include <stdlib.h>
#include "include/carnet.h"

int main(int argc, char const *argv[])
{
    int choix = 0;
    Carnet book;
    init_carnet(&book);
    P p = NULL;
    char *nom,*num;
    nom = (char *)malloc(sizeof(char));
    num = (char *)malloc(sizeof(char));
     do
    {
        printf("/****************************************************/\n\tBienvenue dans votre carnet electronique\n/****************************************************/\n");
        printf("Veuiller choisir une option\n");
        printf("1-Ajouter une personne au carnet\n");
        printf("2-Afficher le carnet\n");
        printf("3-Quitter le programme\n");
        scanf("%d",&choix);

        switch (choix)
        {
            case 1:{
                printf("Entrer le nom et le numero du contact a enregistrer\n");
                scanf("%s%s",nom,num);
                p = create_person(nom,num,p);
                add_person(&book,p);
                printf("Enregistrement reussi\n");
                break;
            }
            case 2:{
                if (book.compteur == 0)
                   goto label; 
                else
                {
                    Tri_Alpha(&book);
                }
                label:
                print_carnet(book);
                break;
            }
            case 3:
                exit(0);
        
            default:
                break;
        }
    } while (choix != 3);
    
    
    return 0;
}