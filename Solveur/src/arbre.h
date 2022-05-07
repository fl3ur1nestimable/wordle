#ifndef ARBRE_H
#define ARBRE_H

typedef struct {
    char etiquette;
    struct noeud *liste_fils;
}noeud;

typedef struct {
    struct noeud *root;

}arbre_mots;


#endif /* ARBRE_H */