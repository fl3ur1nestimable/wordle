#include "struct.h"
#include "mot.h"
#include "arbre.h"
#include "pattern.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int longueur = 2;

mot *mot_create(char *str){
    mot *m = malloc(sizeof(mot));
    m->val = str;
    m->entropy = 0;
    return m;
}

void mot_destroy(mot *mot){
    free(mot);
}

int str_occurences(char* str,char c){
    //printf("%s %c\n",str,c);
    int count = 0;
    for(int i=0;i<(int)strlen(str);i++){
        if(str[i]==c){
            count += 1;
        }
    }
    return count;
}
int mot_occurences_pattern(mot *m,pattern *p,char c){
    char* str = m->val;
    int count = 0;
    for(int i =0;i<p->size;i++){
        if((str[i]==c)&&((p->tab[i]==1)||(p->tab[i])==2)){
            count += 1;
        }
    }
    return count;

}


void mot_arbre_explore(arbre_mots *arbre,noeud *node,int depth,char* str,mot *best, pattern **patterns){
    if(node==NULL){
        return ;
    }
    // On ajoute la lettre du noeud au string str pour avoir le mot parcouru
    str[depth]=node->etiquette;
    // Cas de base : le noeud est une feuille, on obtient donc un mot 
    if(noeud_est_feuille(node)){
        mot *m = mot_create(str);
        //printf("%s ",m->val);
        // Calcul de la moyenne des entropies associés à tous les patternes
        double e = moy_entropy(patterns,m,arbre,depth+1);
        //printf("_ %f\n",e);
        if(e>=best->entropy){
            best->entropy = e;
            strcpy(best->val,m->val);
            printf("%s _ %f\n",best->val,best->entropy);
        }
        free(m);
        noeud *current = node->next;
        return;
    }
    // Appels récursifs sur les descendants
    noeud *current = node->liste_fils->head;
    while(current != NULL){
        mot_arbre_explore(arbre,current,depth+1,str,best,patterns);
        current = current->next;
        str[strlen(str)-1]='\0';
    }
    //printf("\n   %s   \n",best->val);
    return ;
}

void mot_generate_best(arbre_mots *one_arbre,mot *m,int taille_mot){
    char str_current[12]="";
    pattern **patterns = pattern_init_all(taille_mot);
    noeud *current = one_arbre->root->head;
    while (current!=NULL){
        mot_arbre_explore(one_arbre,current,0,str_current,m,patterns);
        current = current->next;
        //str[strlen(str)-1]='\0';
    }
    patterns_destroy(patterns);
    printf("\n%s",m->val);
    printf("__%f\n",m->entropy);
    return ;
}


/*
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

*/

