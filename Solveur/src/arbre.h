#ifndef ARBRE_H
#define ARBRE_H
#include "pattern.h"
#include "mot.h"
typedef struct {
    char etiquette;
    struct noeud *liste_fils;
}noeud;

typedef struct {
    struct noeud *root;
}arbre_mots;
#endif /* ARBRE_H */

double proba(arbre_mots one_arbre,char* mot, pattern pat);

arbre_mots arbre_init(int taille);

arbre_mots* arbre_update(arbre_mots one_arbre, mot mot, pattern pat);

int taille_arbre(arbre_mots one_arbre);
