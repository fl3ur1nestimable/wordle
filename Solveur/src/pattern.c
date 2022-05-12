#include "pattern.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

pattern** pattern_init_all(int taille ){

}

double entropy_pat(pattern* one_pattern, char * mot, double proba){
    //redondance ??
}

double* list_entro(pattern* pattern, char* mot, double proba){

}

pattern *pattern_from_input(int* tab,int taille){
    pattern* p = malloc(sizeof(pattern));
    p->entropy=0;
    p->size = taille;
   // p->tab = malloc(taille*sizeof(int));
    p->tab=tab;
    return p;
}

void pattern_print(pattern *one_pattern){
    printf("[ ");
    for (int i = 0; i < one_pattern->size; i++)
    {
        printf("%d ",one_pattern->tab[i]);
    }
    printf("]\n");
}

void pattern_destroy(pattern* one_pattern){
    free(one_pattern->tab);
    free(one_pattern);
}
