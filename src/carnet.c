#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/carnet.h"

/* Instancier une personne*/
  P create_person(char *name, char *num,P p){
    P person;
    person = malloc(sizeof(Personne));
    person->nom = (char *)malloc(strlen(name)+1);
    person->numero = (char *)malloc(strlen(num)+1);
    strcpy(person->nom,name);
    strcpy(person->numero,num);
    person->next = p;
    return person;
}

/*Afficher le nom et le numero d'une personne*/
void print_person(Personne p){
    printf("Nom complet: %s\n",p.nom);
    printf("Numéro: %s\n",p.numero);
    //printf("suivant: %p\n",p.next);
}

/*Initialiser le compteur du carnet*/
void init_carnet(Carnet *c){
     c->compteur = 0;
}

/*Enregistrer une personne dans le carnet*/
void add_person(Carnet *c,P p){
   c->Tab = malloc(sizeof(p)); 
   c->Tab[c->compteur] = *p;
   c->compteur++;

}

/*Afficher les enregistrements du carnet*/
void print_carnet(Carnet c){
    if(c.compteur == 0){
        printf("Le carnet est vide\n");
    }else{
        for(int i=0;i< c.compteur;i++){
            printf("-----\n%de contact\n-----\n",i+1);
            print_person(c.Tab[i]);
        }
    }   
}

/*Trier le carnet par odre alphabetique*/
void Tri_Alpha(Carnet *c){
    int i,j;//INDICE DE PARCOURS DU TABLEAU,
    char *cle; //variable tampon
    cle = (char *)malloc(sizeof(char));
    printf("Heree1\n");
    for(i = 1; i < c->compteur; i++)
    {
        strcpy(cle,c->Tab[i].nom);
        printf("Heree2\n");
        j = i-1;
        while(j>=0 && (strcmp(c->Tab[j].nom,cle) > 0)){
            strcpy(c->Tab[j + 1].nom,c->Tab[j].nom);
            printf("Heree3\n");
            strcpy(c->Tab[j + 1].numero,c->Tab[j].numero);
            j--;
        }
        strcpy(c->Tab[j + 1].nom, cle);
    }
}