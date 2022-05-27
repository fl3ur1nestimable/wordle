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
    //lecture_fichier(arbre,5);
    arbre_append_mot(arbre,"AMOUR");
    arbre_append_mot(arbre,"TUILE");
    arbre_append_mot(arbre,"TARIF");
    arbre_append_mot(arbre,"BABAR");
    arbre_append_mot(arbre,"CHIEN");
    arbre_append_mot(arbre,"FUITE");
    int tab[]={0,2,1,0,0};
    pattern *pat = pattern_from_input(tab,5);
    mot *m = mot_create("ZAAZZ");
    //printf("%c\n",arbre->root->head->etiquette);

    printf("Taille : %d\n",taille_noeud(arbre->root));
    arbre_init_nb_mots(arbre);
    printf("Nombre de mots dans l'abre : %d\n",arbre->nb_mots);
    printf("Proba : %f\n",proba(arbre,m,pat));

    //printTree(arbre);

    //arbre_mots *new_arbre = arbre_update(arbre,m,pat);

    //printTree(arbre);

    //printf("%c\n",arbre->root->head->etiquette);

    //printf("%c\n",arbre->root->head->next_node->head->etiquette);
    //printf("%c\n",arbre->root->head->next_node->head->next->etiquette);
    //destroy_arbre(new_arbre);
    destroy_arbre(arbre);
    mot_destroy(m);
    pattern_destroy(pat);

    return EXIT_SUCCESS;
}
