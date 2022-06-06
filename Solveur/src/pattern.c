#include "struct.h"
#include "pattern.h"
#include "arbre.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//génére tous les pattern possibles de résultat du wordle en fonction de la taille du mot
pattern** pattern_init_all(int taille){
    pattern ** pat_list = malloc(pow(3,taille)*sizeof(pattern));
    for (int i = 0; i < pow(3,taille); i++)
    {
        pat_list[i]=malloc(sizeof(pattern));
        pat_list[i]->entropy=0;
        pat_list[i]->size=taille;
        char sa[10];
        int b = base3(i);
        sprintf(sa,"%d",b);
        int len = sprintf(sa,"%d",b);
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

//Converti un entier base2 en base3
int base3(int n){
    int r = 0;
    int f = 1;
    int a = n;
    while (a > 0)
    {
        r += abs(a%3)*f;
        a = a/3;
        f *= 10;
    }
    return r;
}

//Calcul de l'entropie d'un pattern, pour un mot et un arbre donnés
double entropy_pat(pattern* one_pattern, mot* m, arbre_mots *arbre){
    double p  = arbre_proba(arbre,m,one_pattern);
    //printf("_%f_",p);
    double e = 0;
    if(p!=0){
        e = p*log(1/p);
        //printf("---%f-",e);
    }
    return e;
}

//Calcul de la moyenne des entropie pour un mot donné
double moy_entropy(pattern** patterns, mot* m,arbre_mots *arbre,int taille){
    double e_moy=0;
    int tot = pow(3,taille);
    for (int i = 0; i < tot; i++)
    {
        e_moy+=entropy_pat(patterns[i],m,arbre);
    }
    //e_moy=e_moy/tot;
    return e_moy;
}

//Génération d'un pattern à partir de l'entrée utilisateur (tableau)
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

//affichage d'un pattern
void pattern_print(pattern *one_pattern){
    printf("[ ");
    for (int i = 0; i < one_pattern->size; i++)
    {
        printf("%d ",one_pattern->tab[i]);
    }
    printf("]\n");
}

//Libération de la mémoire allouée lors de la création d'un pattern
void pattern_destroy(pattern* one_pattern){
    free(one_pattern->tab);
    free(one_pattern);
}

//Libération de la mémoire allouée lors de la création de tous les patterns
void patterns_destroy(pattern **patterns){
    int tot = pow(3,patterns[0]->size);
    for (int i = 0; i < tot; i++){
        pattern_destroy(patterns[i]);
    }
    free(patterns);
}



