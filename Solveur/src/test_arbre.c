#include "struct.h"
#include "arbre.h"
#include "mot.h"
#include "pattern.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){

    arbre_mots *arbre = arbre_init();
    assert(arbre!=NULL);
    arbre_append_mot(arbre,"AMOUR");
    arbre_append_mot(arbre,"TUILE");
    arbre_append_mot(arbre,"TARIF");
    arbre_append_mot(arbre,"BABAR");
    arbre_append_mot(arbre,"CHINA");
    arbre_append_mot(arbre,"FUITE");
    arbre_append_mot(arbre,"ARABI");
    arbre_append_mot(arbre,"FRITE");
    arbre_init_nb_mots(arbre);

    assert(arbre->nb_mots==8);
    assert(arbre->root->head->nb_mots==2);
    assert(arbre->root->head->next->nb_mots==2);

    int tab[]={1,2,0,0,0};
    pattern *pat = pattern_from_input(tab,5);
    mot *m = mot_create("IABZZ");

    assert(mot_occurences_pattern(m,pat,'A')==1);
    /*
    printTree(arbre);
    printf("Nombre de mots dans l'arbre : %d\n",arbre->nb_mots);
    int t = arbre_nb_mot(arbre,m,pat);
    printf("\n\n");
    arbre_update(arbre,m,pat);
    arbre_init_nb_mots(arbre);
    printTree(arbre);
    printf("Nombre de mots dans l'arbre : %d\n",t);
    printf("Nombre de mots dans l'arbre : %d\n",arbre->nb_mots);
    */
    int tab2[]={0,0,0,2,0};
    pattern *pat2 = pattern_from_input(tab2,5);
    mot *m2 = mot_create("ZZZIZ");
    /*
    arbre_update(arbre,m2,pat2);
    arbre_init_nb_mots(arbre);
    printTree(arbre);
    printf("Nombre de mots dans l'arbre : %d\n",arbre->nb_mots);
*/
    
    arbre_mots *arbre2 = arbre_init();
    lecture_fichier(arbre2,5);
    arbre_init_nb_mots(arbre2);
    
    //printTree(arbre2);
    int tab3[]={1,0,1,1,0};
    pattern *pat3 = pattern_from_input(tab3,5);
    mot *m3 = mot_create("AMOUR");
    printf("Nb mots : %d\n",arbre2->nb_mots);
    printf("Nb mots après coupure : %d\n",arbre_nb_mot(arbre2,m3,pat3));
    printf("Proba : %f\n",proba(arbre2,m3,pat3));
    arbre_update(arbre2,m3,pat3);
    arbre_init_nb_mots(arbre2);
    printTree(arbre2);
    printf("Nb mots : %d\n",arbre2->nb_mots);

    int tab4[]={1,1,1,0,0};
    pattern *pat4 = pattern_from_input(tab4,5);
    mot *m4 = mot_create("UBACS");
    printf("Nb mots après coupure : %d\n",arbre_nb_mot(arbre2,m4,pat4));
    printf("Proba : %f\n",proba(arbre2,m4,pat4));
    arbre_update(arbre2,m4,pat4);
    arbre_init_nb_mots(arbre2);
    printTree(arbre2);
    printf("Nb mots : %d\n",arbre2->nb_mots);

    int tab5[]={1,1,1,1,1};
    pattern *pat5 = pattern_from_input(tab5,5);
    mot *m5 = mot_create("TABOU");
    printf("Nb mots après coupure : %d\n",arbre_nb_mot(arbre2,m5,pat5));
    printf("Proba : %f\n",proba(arbre2,m5,pat5));
    arbre_update(arbre2,m5,pat5);
    arbre_init_nb_mots(arbre2);
    printTree(arbre2);
    printf("Nb mots : %d\n",arbre2->nb_mots);



    // Destroy
    arbre_destroy(arbre);
    arbre_destroy(arbre2);
    mot_destroy(m);
    pattern_destroy(pat);
    mot_destroy(m2);
    pattern_destroy(pat2);
    mot_destroy(m3);
    pattern_destroy(pat3);
    mot_destroy(m4);
    pattern_destroy(pat4);
    mot_destroy(m5);
    pattern_destroy(pat5);

    return EXIT_SUCCESS;
}
