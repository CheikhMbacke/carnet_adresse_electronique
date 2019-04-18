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
    if(c->compteur == 0)
        c->Tab = malloc(sizeof(Personne));
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
    char *cleNom,*cleNum; //variable tampon
    cleNom = (char *)malloc(sizeof(char));
    cleNum = (char *)malloc(sizeof(char));
    for(i = 1; i < c->compteur; i++)
    {
        strcpy(cleNom,c->Tab[i].nom);
        strcpy(cleNum,c->Tab[i].numero);
        j = i-1;
        while(j>=0 && (strcmp(c->Tab[j].nom,cleNom) > 0)){
            strcpy(cleNom,c->Tab[j].nom);
            strcpy(cleNum,c->Tab[j].numero);
            j--;
        }
        strcpy(c->Tab[j + 1].nom, cleNom);
        strcpy(c->Tab[j + 1].numero, cleNum);
    }
}

/*Sauvegarde de donnees*/
void save_data(FILE *fic, char *nom,char* num){

    fic=fopen("saveFile.txt","a+");

    fprintf(fic,"%s %s\n",nom,num);
   
    fclose(fic);
}
/* 
void restaure_data(FILE *fic, Carnet *c){
    int i = 0;
    while(!feof(fic)){
        fscanf(fic,"%s %s",c->Tab[i].nom,c->Tab[i].numero);
    }
    
}
 */