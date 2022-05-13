#include "pattern.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

pattern** pattern_init_all(int taille ){
    pattern ** pat_list = malloc(pow(3,taille)*sizeof(pattern));
    for (int i = 0; i < pow(3,taille); i++)
    {
        pat_list[i]=malloc(sizeof(pattern));
        pat_list[i]->entropy=0;
        pat_list[i]->size=taille;
        char *sa=malloc(taille+1);
        long b = base3(i);
        switch (taille)
        {
        case 3:
            snprintf(sa, sizeof(sa), "%03lu",b);
            break;
            
        case 4:
            snprintf(sa, sizeof(sa), "%04lu",b);
            break;
        case 5:
            snprintf(sa, sizeof(sa), "%05lu",b);
            break;
        case 6:
            snprintf(sa, sizeof(sa), "%06lu",b);
            break;
        case 7:
            snprintf(sa, sizeof(sa), "%07lu",b);
            break;
        case 8:
            snprintf(sa, sizeof(sa), "%08lu",b);
            break;
        case 9:
            snprintf(sa, sizeof(sa), "%09lu",b);
            break;
        case 10:
            snprintf(sa, sizeof(sa), "%010lu",b);
            break;
        }
        pat_list[i]->tab = sa;
    }
    return pat_list;
}

long base3(int n){
    long r = 0;
    long f = 1;
    int a = n;
    while (a > 0)
    {
        r += abs(a%3)*f;
        a = a/3;
        f *= 10;
    }
    return r;
}

/*double entropy_pat(pattern* one_pattern, char * mot, double proba){
    //redondance ??
}

double* list_entro(pattern* pattern, char* mot, double proba){

}*/

pattern *pattern_from_input(char* tab,int taille){
    pattern* p = malloc(sizeof(pattern));
    p->entropy=0;
    p->size = taille;
    p->tab=tab;
    return p;
}

void pattern_print(pattern *one_pattern){
    printf("[ ");
    for (int i = 0; i < one_pattern->size; i++)
    {
        printf("%c ",one_pattern->tab[i]);
    }
    printf("]\n");
}

void pattern_destroy(pattern* one_pattern){
    free(one_pattern->tab);
    free(one_pattern);
}
