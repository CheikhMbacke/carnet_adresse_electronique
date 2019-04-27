nclude <string.h>

//structutre de type personne
//struct personne 
typedef struct personne
{
    char *nom;
    char *telephone;
    struct personne *saut;
} personne *p;


//structutre de type carnet d'adresse
typedef struct carnet
	{
	ptab;	
	int nb_element;
	} carnet;


//fonction renvoyant un pointeur vers une structure personne
 personne* renvoyer(char *nom,char *telephone,personne,saut)
	{
		personne p1=malloc(sizeof(personne));
		p1->nom=(char*)malloc(strlen(nom)+1);
		p1->telephone=(char*)malloc(strlen(telephone)+1);
		p1->saut=saut;
		strcpy(p1->nom,nom);
		strcpy(p1->telephone,telephone);
		return p1;
	}
