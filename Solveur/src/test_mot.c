#include "struct.h"
#include "mot.h"
#include "arbre.h"
#include "pattern.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>


int main(){
    arbre_mots *arbre = arbre_init();
    // Test avec arbre qu'on crée à la main

    /*
    arbre_append_mot(arbre,"AMOUR");
    arbre_append_mot(arbre,"TUILE");
    arbre_append_mot(arbre,"TARIF");
    arbre_append_mot(arbre,"BABAR");
    arbre_append_mot(arbre,"CHINA");
    arbre_append_mot(arbre,"FUITE");
    arbre_append_mot(arbre,"ARABI");
    arbre_append_mot(arbre,"FRITE");
    arbre_init_nb_mots(arbre);
    */

    // Test en créant l'arbre à partir du dictionnaire et en faisant les étapes à la main

    /*
    lecture_fichier(arbre,5);
    //printTree(arbre);
    printf("\nNb mots dans l'arbre : %d\n",arbre->nb_mots);
    char str[7]="TIRAS";
    mot *mot1 = mot_create(str);
    mot1->entropy = 4.047893;
    //mot_generate_best(arbre,mot1,5);
    printf("\nmot : %s \nentropie : %f\n",mot1->val,mot1->entropy);

    int tab[]={0,0,2,2,2};
    pattern *pat = pattern_from_input(tab,5);
    arbre_update(arbre,mot1,pat);
    printf("\nNb mots : %d",arbre->nb_mots);

    mot_generate_best(arbre,mot1,5);

    printf("\nmot : %s \nentropie : %f\n",mot1->val,mot1->entropy);
    int tab2[] = {0,1,2,2,2};
    pattern *pat2 = pattern_from_input(tab2,5);
    arbre_update(arbre,mot1,pat2);
    printTree(arbre);
    printf("\nNb mots : %d\n",arbre->nb_mots);

    mot_generate_best(arbre,mot1,5);


    pattern_destroy(pat);
    pattern_destroy(pat2);

    mot_destroy(mot1);
    */

    lecture_fichier(arbre,4);
    int essais = 0;
    char str[10]="RAIE";
    char c[10]="EBLA";
    mot *m = mot_create(str);
     
    

    pattern *pat = pattern_from_mot(m->val,c,4);
    pattern_print(pat);
    //pattern_print(pat);
    //printf("GUESS : %s / MOT solution : %s\n",m->val,c);
    arbre_update(arbre,m,pat);
    essais+=1;
    mot_generate_best(arbre,m,4);
    printf("%s\n",m->val);
    printf("%d\n",arbre->nb_mots);
    
    pattern_destroy(pat);
    pattern *pat2 = pattern_from_mot(m->val,c,4);
    pattern_print(pat2);
    printf("%s\n",m->val);
    arbre_update(arbre,m,pat2);
    essais+=1;
    mot_generate_best(arbre,m,4);
    printf("%s\n",m->val);
    printf("%d\n",arbre->nb_mots);
    
    //printTree(arbre);
    pattern_destroy(pat2);

    mot_destroy(m);

    //mot_destroy(mot2);
    //mot_destroy(mot3);
    arbre_destroy(arbre);

    return EXIT_SUCCESS;
}

