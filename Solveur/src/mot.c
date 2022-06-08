#include "struct.h"
#include "mot.h"
#include "arbre.h"
#include "pattern.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Crée un mot avec le string str comme valeur et d'entropie nulle
mot *mot_create(char *str){
    mot *m = malloc(sizeof(mot));
    m->val = str;
    m->entropy = 0;
    return m;
}
// Détruit (free) le mot
void mot_destroy(mot *mot){
    free(mot);
}

// Renvoie le nombre d'occurences du charactère c dans le string str 
int str_occurences(char* str,char c){
    int count = 0; // Initialisation compteur d'occurence du charactère c
    for(int i=0;i<(int)strlen(str);i++){
        if(str[i]==c){
            count += 1;
        }
    }
    return count;
}
// Renvoie le nombre d'occurence du charactère c dans le mot caché derrière l'association du mot m et du patterne p
int mot_occurences_pattern(mot *m,pattern *p,char c){
    char* str = m->val;
    int count = 0;
    for(int i =0;i<p->size;i++){
        if((str[i]==c)&&((p->tab[i]==1)||(p->tab[i])==2)){ // On ajoute 1 au compteur ssi on a égalités des charactères et qu'on a un 1 ou un 2 sur le pattern 
            count += 1;
        }
    }
    return count;

}


// Explore toutes les branches de l'arbre pour former tous les mots de la liste, calcule leur entropie, stocke dans le mot best celui avec la meilleur entropie
void mot_arbre_explore(arbre_mots *arbre,noeud *node,int depth,char* str,mot *best, pattern **patterns){
    if(node==NULL){
        return ;
    }
    str[depth]=node->etiquette; // On ajoute la lettre du noeud au string str pour avoir le mot parcouru
    if(noeud_est_feuille(node)){ // Cas de base : le noeud est une feuille, on obtient donc un mot 
        mot *m = mot_create(str); // Création du mot obtenu 
        double e = moy_entropy(patterns,m,arbre,depth+1); // Calcul de son entropie à partir de tous les patternes
        if(e>=best->entropy){ // Si son entropie est meilleure que notre meilleur mot actuel(best), on change best
            best->entropy = e;
            strcpy(best->val,m->val);
            //printf("%s _ %f\n",best->val,best->entropy);
        }
        free(m); // On détruit le mot parcouru
        return;
    }
    // Appels récursifs sur les descendants
    noeud *current = node->liste_fils->head;
    while(current != NULL){
        mot_arbre_explore(arbre,current,depth+1,str,best,patterns);
        current = current->next;
        str[strlen(str)-1]='\0'; // Comme on est passé au voisin, on supprime la lettre de son prédécesseur
    }
    return ;
}
// Stocke dans le mot m le mot avec la plus grande entropie dans l'arbre 
void mot_generate_best(arbre_mots *one_arbre,mot *m,int taille_mot){
    m->entropy = 0; // Le mot m est notre meilleur mot pour l'instant (on réinitialise son entropy à 0)
    char str_current[12]=""; // Initialisation du string qui contiendra le mot parcouru dans l'arbre
    pattern **patterns = pattern_init_all(taille_mot); // On crée tous les patterns possibles
    noeud *current = one_arbre->root->head; // On commence à parcourir l'arbre par son premier noeud
    while (current!=NULL){
        mot_arbre_explore(one_arbre,current,0,str_current,m,patterns); // On explore les branches de l'arbre pour obtenir un mot
        current = current->next; // On passe à son voisin
    }
    patterns_destroy(patterns);
    return ;
}



