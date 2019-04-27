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
    if((c.compteur) == 0){
        printf("Le carnet est vide\n");
    }else{
        for(int i=0;i< c.compteur;i++){
            printf("-----\n%de contact\n-----\n",i+1);
            print_person(c.Tab[i]);
        }
    }   
}

 /* /*Trier le carnet par odre alphabetique*/
void Tri_Alpha(Carnet *c){
    int i,j;//INDICE DE PARCOURS DU TABLEAU,
    char *cle = (char *)malloc(sizeof(char)); //variable tampon

    for(i = 1; i < c->compteur; i++)
    {
        strcpy(cle,c->Tab[i].nom);
        j = i-1;
        while(j>=0 && (strcmp(c->Tab[j].nom,cle) > 0)){
            strcpy(c->Tab[j+1].nom,c->Tab[j].nom);
            strcpy(c->Tab[j+1].numero,c->Tab[j].numero);
            j--;
        }
        strcpy(c->Tab[j+1].nom,cle);
        strcpy(c->Tab[j+1].numero,c->Tab[i].numero);
    }
} 

/*Sauvegarde de donnees*/
void save_data(FILE *fic,Carnet c){

    fic=fopen("saveFile.txt","a+");
    for(int i = 0; i < c.compteur; i++){
            fprintf(fic,"%s %s\n",c.Tab[i].nom,c.Tab[i].numero);
        }
    fclose(fic);
}
/**
 * Restaurer les donnees dans le carnet
*/
int is_empty_file(FILE *file){
    char caractere;
    if ((caractere = fgetc(file)) == EOF)
        return 0;
    return 1;   
}
void restaure_data(FILE *fic, Carnet *c){
    fic = fopen("saveFile.txt","r");
    P person = NULL;
    char *nom,*num;
    nom = (char *)malloc(sizeof(char));
    num = (char *)malloc(sizeof(char));
    if (fic == NULL) {
        fprintf(stderr,"Erreur d'ouverture du fichier ");
        return;
    }
    if (is_empty_file(fic)) {
        rewind(fic);
        while(1){
            if (feof(fic)){
                return;
            }else
            {
                fscanf(fic,"%s %s",nom,num);
                person = create_person(nom,num,person);
                add_person(c,person);
            }
        }
    free(nom);
    free(num);
    }
    fclose(fic);
}
