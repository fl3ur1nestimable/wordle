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
    arbre_init_nb_mots(arbre);

    assert(arbre->nb_mots==6);
    assert(arbre->root->head->nb_mots==1);
    assert(arbre->root->head->next->nb_mots==2);

    int tab[]={0,1,0,0,0};
    pattern *pat = pattern_from_input(tab,5);
    mot *m = mot_create("ZAZZZ");

    printTree(arbre);
    printf("Nombre de mots dans l'arbre : %d\n",arbre->nb_mots);
    int t = arbre_nb_mot(arbre,m,pat);
    arbre_update(arbre,m,pat);
    printTree(arbre);
    arbre_init_nb_mots(arbre);
    printf("Nombre de mots dans l'arbre : %d\n",t);
    printf("Nombre de mots dans l'arbre : %d\n",arbre->nb_mots);

    int tab2[]={0,0,2,0,0};
    pattern *pat2 = pattern_from_input(tab2,5);
    mot *m2 = mot_create("ZZIZZ");
    arbre_update(arbre,m2,pat2);
    printTree(arbre);

    arbre_mots *arbre2 = arbre_init();
    lecture_fichier(arbre2,5);
    arbre_init_nb_mots(arbre2);
    printTree(arbre2);
    int tab3[]={2,2,0,0,0};
    pattern *pat3 = pattern_from_input(tab3,5);
    mot *m3 = mot_create("ABRAS");
    printf("Nb mots : %d\n",arbre2->nb_mots);
    printf("Nb mots après coupure : %d\n",arbre_nb_mot(arbre2,m3,pat3));
    printf("Proba : %f\n",proba(arbre2,m3,pat3));
    arbre_update(arbre2,m3,pat3);
    printTree(arbre2);
    arbre_init_nb_mots(arbre2);
    printf("%d\n",arbre2->nb_mots);
    

    // Destroy
    arbre_destroy(arbre);
    arbre_destroy(arbre2);
    mot_destroy(m);
    pattern_destroy(pat);
    mot_destroy(m2);
    pattern_destroy(pat2);
    mot_destroy(m3);
    pattern_destroy(pat3);

    return EXIT_SUCCESS;
}
