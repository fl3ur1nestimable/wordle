#include "struct.h"
#include <stdbool.h>

#ifndef MOT_H
#define MOT_H

/*

struct _noeud{
    char etiquette;
    struct _liste *liste_fils;
    struct _noeud *next;
};
typedef struct _noeud noeud;

struct _liste{
    struct _noeud *head;
};
typedef struct _liste liste;

typedef struct {
    noeud *root;
}arbre_mots;

*/

mot *mot_create(char *str);

void mot_destroy();

int mot_occurences(char* str,char c);

/*

bool noeud_is_empty(noeud *one_noeud);

void mot_arbre_explore(noeud *one_noeud, char* str, mot *best);

bool noeud_is_last(noeud *one_noeud);

void mot_generate_best(arbre_mots *one_arbre);

char* mot_get_val(mot *mot);

double mot_entropy(double *list_entro);

*/

#endif /* MOT_H */
