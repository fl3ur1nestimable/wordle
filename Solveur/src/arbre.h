#include "mot.h"
#include "pattern.h"
#ifndef ARBRE_H
#define ARBRE_H

struct _list_ele{
    char* etiquette;
    struct _list_ele* next;
    struct _noeud* next_node;
};
typedef struct _list_ele list_ele;

struct _noeud
{
    list_ele* head;
    int size;

};
typedef struct _noeud noeud;


 struct _arbre_mots{
    noeud *root;
};
typedef  struct _arbre_mots arbre_mots;


//double proba(arbre_mots* one_arbre,char* mot, pattern pat);
void arbre_append_mot(arbre_mots* arbre, char* m);
arbre_mots* arbre_init();
noeud* node_init();
void lecture_fichier(arbre_mots* arbre, int n);
list_ele* list_ele_init(char* val);
void arbre_append(noeud* node, char* val);
void remove_ele(noeud* node, char* c);
arbre_mots* arbre_update(arbre_mots* one_arbre, mot* mots, pattern *pat);
void remove_node(noeud* node);
int taille_arbre(arbre_mots *one_arbre);
#endif /* ARBRE_H */
