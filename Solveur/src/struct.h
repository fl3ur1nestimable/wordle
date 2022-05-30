#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    char* val;
    double entropy;
}mot;


struct _noeud{
    char etiquette;
    struct _noeud* next;
    struct _noeud* prev;
    struct _noeud* parent;
    struct _liste* liste_fils;
    int nb_mots;
};
typedef struct _noeud noeud;

struct _liste
{
    noeud* head;
    int size;
    int nb_mots;

};
typedef struct _liste liste;


 struct _arbre_mots{
    liste *root;
    int nb_mots;
};
typedef  struct _arbre_mots arbre_mots;

typedef struct {
    int *tab;
    double entropy;
    int size;
}pattern;




#endif /* STRUCT_H */
