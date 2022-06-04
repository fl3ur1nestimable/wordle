#ifndef PATTERN_H
#define PATTERN_H

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


pattern** pattern_init_all(int taille );

double entropy_pat(pattern* one_pattern, mot* m,arbre_mots *arbre);

double moy_entropy(pattern** patterns, mot* m, arbre_mots *arbre,int taille);

pattern *pattern_from_input(int* tab,int taille);

void pattern_print(pattern *one_pattern);

void pattern_destroy(pattern* one_pattern);

void patterns_destroy(pattern **patterns);

long base3(int n);

#endif /* PATTERN_H */
