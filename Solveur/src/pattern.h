#ifndef PATTERN_H
#define PATTERN_H


typedef struct {
    int *tab;
    double entropy;
}pattern;


#endif /* PATTERN_H */
pattern* pattern_init(int taille );

double entropy_pat(pattern* one_pattern, char * mot, double proba);

double* list_entro(pattern* pattern, char* mot, double proba);

pattern pattern_from_input(int* tab);

