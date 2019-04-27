#include <stdio.h>
#ifndef __CARNET__H__
#define __CARNET__H__

/**/
typedef struct Personne{
    char *nom;
    char *numero;
    struct Personne *next;
}Personne ,*P;

/**/
typedef struct Carnet{
    P Tab;
    int compteur;
}Carnet;

/*Definition de fonction*/

/* Instancier une personne*/
P create_person(char *name, char *num,P p );

/*Afficher le nom et le numero d'une personne*/
void print_person(Personne p);

/*Initialiser le compteur du carnet*/
void init_carnet(Carnet *c);

/*Enregistrer une personne dans le carnet*/
void add_person(Carnet *c,P p);

/*Afficher les enregistrements du carnet*/
void print_carnet(Carnet c);

/*Trier le carnet par odre alphabetique*/
void Tri_Alpha(Carnet *c);

/*Sauvegarde de donnees*/
void save_data(FILE *fic,Carnet c);
int is_empty_file(FILE *file);
/**
 * Restaurer les donnees dans le carnet
*/
void restaure_data(FILE *fic, Carnet *c);
#endif