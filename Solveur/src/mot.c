#include "pattern.h"

#include "mot.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int longueur = 2;

mot *mot_create(char *str){
    mot *m = malloc(sizeof(mot));
    m->val = str;
    return m;
}

void mot_destroy(mot *mot){
    free(mot);
}

char* mot_get_val(mot *mot){
    return mot->val;
}

bool noeud_is_empty(noeud *one_noeud){
    return one_noeud->liste_fils->head==NULL;
}

bool noeud_is_last(noeud *one_noeud){
    return one_noeud->next==NULL;
}

void mot_arbre_explore(noeud *one_noeud,char* str,mot *best){
    str[strlen(str)] = one_noeud->etiquette;
    if (noeud_is_empty(one_noeud)){
        if(noeud_is_last(one_noeud)){
            printf("%s\n",str);
            mot *m = mot_create(str);
            //double *e = list_entro(*pattern,mot,proba);
            //if(e>best->entropy){
                //m->entropy = e;
                //best = m;
            //}
            free(m);
            return;
        }
        printf("%s\n",str);
        mot *m = mot_create(str);
        str[strlen(str)-1]='\0';
        mot_arbre_explore(one_noeud->next,str,best);
        free(m);
        return;
    }
    mot_arbre_explore(one_noeud->liste_fils->head,str,best);
    if(!noeud_is_last(one_noeud)){
        str[strlen(str)-1]='\0';
        str[strlen(str)-1]='\0';
        mot_arbre_explore(one_noeud->next,str,best);
    }
}


void mot_generate_best(arbre_mots *one_arbre){
    // parcours de l'arbre
    char str[5]="";
    noeud *racine = one_arbre->root;
    noeud *current = racine->liste_fils->head;
    mot *best = mot_create(str);
    best->entropy=0.;
    mot_arbre_explore(current,str,best);
    printf("E : %f \n",best->entropy);
    free(best);
    return;
}

