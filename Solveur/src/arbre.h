#include "struct.h"
#include <stdbool.h>
#ifndef ARBRE_H
#define ARBRE_H


//double proba(arbre_mots* one_arbre,char* mot, pattern pat);
arbre_mots* arbre_init();
liste* liste_init();
noeud* noeud_init(char val,noeud *prev,noeud *parent);

void lecture_fichier(arbre_mots* arbre, int n);
void arbre_append_mot(arbre_mots* arbre, char* m);

bool liste_remove_noeud(liste* l, noeud *current);
void arbre_update(arbre_mots* one_arbre, mot* m, pattern *pat);
void liste_update(liste *l,mot *m, pattern *pat,int depth,char* str);
void noeud_update(arbre_mots *arbre, noeud *node,mot *m, pattern* pat, int depth,char* str);
void remove_liste(liste* l);
void noeud_remove(arbre_mots *arbre,noeud *node);

int taille_arbre(arbre_mots *one_arbre);
int taille_liste(liste* l);

void arbre_destroy(arbre_mots *arbre);
void noeud_destroy(noeud *node);

void printTree(arbre_mots *arbre);
void printNTree(noeud* n, bool flag[], int depth, bool isLast);

void arbre_init_nb_mots(arbre_mots *arbre);
int noeud_init_nb_mots(noeud *node);
double proba(arbre_mots* arbre, mot* mot, pattern* one_pattern);
int nb_mots_pat(liste *l,mot *m, pattern *pat,int depth,char* str);

bool noeud_est_feuille(noeud *n);
bool liste_est_vide(liste *l);

#endif /* ARBRE_H */
