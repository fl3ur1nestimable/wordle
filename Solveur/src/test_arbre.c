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
    int tab[]={0,1,0,0,0};
    pattern *pat = pattern_from_input(tab,5);
    mot *m = mot_create("ZAZZZ");
    //noeud_remove(arbre,arbre->root->head->next->liste_fils->head->liste_fils->head);
    printTree(arbre);
    printf("Nombre de mots dans l'abre : %d\n",arbre->nb_mots);
    arbre_update(arbre,m,pat);
    printTree(arbre);
    //printf("Nombre de mots dans l'abre : %d\n",arbre->nb_mots);
    int tab2[]={0,0,2,0,0};
    pattern *pat2 = pattern_from_input(tab2,5);
    mot *m2 = mot_create("ZZIZZ");
    //arbre_update(arbre,m2,pat2);
    //printTree(arbre);



    //printf("%c\n",arbre->root->head->etiquette);

    //printf("Taille : %d\n",taille_noeud(arbre->root));
    //printf("Nombre de mots dans l'abre : %d\n",arbre->nb_mots);
    //printf("Proba : %f\n",proba(arbre,m,pat));
    //arbre_mots *arbre2 = arbre_init();
    //lecture_fichier(arbre2,5);
    //char str[12];
    //mot_arbre_explore(arbre2->root,0,str,m);

    //printf("%c\n",arbre->root->head->etiquette);

    //printf("%c\n",arbre->root->head->next->next_node->head->etiquette);
    //printf("%c\n",arbre->root->head->next_node->head->next->etiquette);
    //arbre_destroy(new_arbre);

    arbre_destroy(arbre);
    //arbre_destroy(arbre2);
    mot_destroy(m);
    pattern_destroy(pat);
    mot_destroy(m2);
    pattern_destroy(pat2);

    return EXIT_SUCCESS;
}
