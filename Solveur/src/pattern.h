#ifndef PATTERN_H
#define PATTERN_H


typedef struct {
    int *tab;
    double entropy;
    int size;
}pattern;



pattern** pattern_init_all(int taille );

double entropy_pat(pattern* one_pattern, char * mot, double proba);

double* list_entro(pattern* pattern, char* mot, double proba);

pattern *pattern_from_input(int* tab,int taille);

void pattern_print(pattern *one_pattern);

void pattern_destroy(pattern* one_pattern);

#endif /* PATTERN_H */
