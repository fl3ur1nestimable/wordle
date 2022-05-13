#ifndef PATTERN_H
#define PATTERN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct {
    char *tab;
    double entropy;
    int size;
}pattern;



pattern** pattern_init_all(int taille );

double entropy_pat(pattern* one_pattern, char * mot, double proba);

double* list_entro(pattern* pattern, char* mot, double proba);

pattern *pattern_from_input(char* tab,int taille);

void pattern_print(pattern *one_pattern);

void pattern_destroy(pattern* one_pattern);

long base3(int n);

#endif /* PATTERN_H */
