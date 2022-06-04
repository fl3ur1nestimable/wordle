#include "struct.h"
#include <stdbool.h>

#ifndef MOT_H
#define MOT_H

mot *mot_create(char *str);

void mot_destroy();

void mot_arbre_explore(arbre_mots *arbre, noeud *node,int depth,char* str,mot *best, pattern **patterns);

int mot_occurences_pattern(mot *m,pattern *p,char c);
int str_occurences(char* str,char c);

void mot_generate_best(arbre_mots *one_arbre,mot *m,int taille_mot);


#endif /* MOT_H */
