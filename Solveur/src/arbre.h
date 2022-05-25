#ifndef ARBRE_H
#define ARBRE_H
#include "pattern.h"
#include "mot.h"
typedef struct {
    char* etiquette;
    struct liste_ele* next;
    struct noeud* next_node;
}list_ele;
typedef struct 
{
    list_ele* head;
    int* size;

}noeud;

typedef struct {
 noeud *root;
}arbre_mots;
#endif /* ARBRE_H */

double proba(arbre_mots one_arbre,char* mot, pattern pat);

arbre_mots* arbre_init(int taille);
noeud* node_init();
void arbre_append_list(arbre_mots* arbre,noeud* node );
void arbre_append(noeud* node, char* val);

arbre_mots* arbre_update(arbre_mots* one_arbre, mot* mot, pattern *pat);

int taille_arbre(arbre_mots one_arbre);
