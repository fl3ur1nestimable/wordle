#include "struct.h"
#include <stdbool.h>

#ifndef MOT_H
#define MOT_H

// Crée un mot avec le string str comme valeur et d'entropie nulle
mot *mot_create(char *str);

// Détruit (free) le mot
void mot_destroy();

// Explore toutes les branches de l'arbre pour former tous les mots de la liste, calcule leur entropie, renvoie le mot avec la meilleur entropie
void mot_arbre_explore(arbre_mots *arbre, noeud *node,int depth,char* str,mot *best, pattern **patterns);

// Renvoie le nombre d'occurence du charactère c dans le mot caché derrière l'association du mot m et du patterne p
int mot_occurences_pattern(mot *m,pattern *p,char c);

// Renvoie le nombre d'occurences du charactère c dans le string str 
int str_occurences(char* str,char c);


void mot_generate_best(arbre_mots *one_arbre,mot *m,int taille_mot);


#endif /* MOT_H */
