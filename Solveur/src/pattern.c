#include "pattern.h"
#include "arbre.h"
#include "mot.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

pattern** pattern_init_all(int taille){
    pattern ** pat_list = malloc(pow(3,taille)*sizeof(pattern));
    for (int i = 0; i < pow(3,taille); i++)
    {
        pat_list[i]=malloc(sizeof(pattern));
        pat_list[i]->entropy=0;
        pat_list[i]->size=taille;
        char sa[10];
        long b = base3(i);
        sprintf(sa,"%lu",b);
        int len = sprintf(sa,"%lu",b);
        int rest = taille - len;
        pat_list[i]->tab=malloc((taille+1)*sizeof(int));
        for (int j = 0; j < taille; j++)
        {
            if (j<rest)
            {
                pat_list[i]->tab[j]=0;
            }
            else{
                pat_list[i]->tab[j]=sa[j-rest]%3;
            }
        }
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

double entropy_pat(pattern* one_pattern, char * mot, arbre_mots *arbre){
    double p  = proba(arbre,mot,one_pattern);
    double e = p*log(1/p);
    return e;
}

double moy_entropy(pattern** patterns, char* mot,arbre_mots *arbre,int taille){
    double e_moy=0;
    int tot = pow(3,taille);
    for (int i = 0; i < tot; i++)
    {
        e_moy+=entropy_pat(patterns[i],mot,arbre);
    }
    e_moy=e_moy/tot;
    return e_moy;
}

pattern *pattern_from_input(int* tab,int taille){
    pattern* p = malloc(sizeof(pattern));
    p->entropy=0;
    p->size = taille;
    p->tab=malloc(taille*sizeof(int));
    for (int i = 0; i < taille; i++)
    {
        p->tab[i]=tab[i];
    }
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
