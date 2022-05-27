#include "struct.h"
#include <stdbool.h>
#ifndef ARBRE_H
#define ARBRE_H


//double proba(arbre_mots* one_arbre,char* mot, pattern pat);
void arbre_append_mot(arbre_mots* arbre, char* m);
arbre_mots* arbre_init();
noeud* node_init();
void lecture_fichier(arbre_mots* arbre, int n);
list_ele* list_ele_init(char val);
void arbre_append(noeud* node, char val);
bool remove_ele(noeud* node, char c);
arbre_mots* arbre_update(arbre_mots* one_arbre, mot* mots, pattern *pat);
void remove_node(noeud* node);
int taille_arbre(arbre_mots *one_arbre);
int taille_noeud(noeud* node);
void destroy_arbre(arbre_mots *arbre);
void destroy_node(noeud *node);
#endif /* ARBRE_H */
