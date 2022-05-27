#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    char* val;
    double entropy;
}mot;


struct _list_ele{
    char etiquette;
    struct _list_ele* next;
    struct _noeud* next_node;
};
typedef struct _list_ele list_ele;

struct _noeud
{
    list_ele* head;
    int size;
    int nb_mots;

};
typedef struct _noeud noeud;


 struct _arbre_mots{
    noeud *root;
    int nb_mots;
};
typedef  struct _arbre_mots arbre_mots;

typedef struct {
    int *tab;
    double entropy;
    int size;
}pattern;




#endif /* STRUCT_H */
