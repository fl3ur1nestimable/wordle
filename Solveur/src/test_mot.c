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
    
    mot1->entropy = 0;
    mot_generate_best(arbre,mot1,5);

    printf("\nmot : %s \nentropie : %f\n",mot1->val,mot1->entropy);
    int tab2[] = {0,1,2,2,2};
    pattern *pat2 = pattern_from_input(tab2,5);
    arbre_update(arbre,mot1,pat2);
    printTree(arbre);
    printf("\nNb mots : %d",arbre->nb_mots);
    mot1->entropy = 0;
    mot_generate_best(arbre,mot1,5);
    

    pattern_destroy(pat);
    pattern_destroy(pat2);
    mot_destroy(mot1);
    //mot_destroy(mot2);
    //mot_destroy(mot3);
    arbre_destroy(arbre);
    
    return EXIT_SUCCESS;
}

