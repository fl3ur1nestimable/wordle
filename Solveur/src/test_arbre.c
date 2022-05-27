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
    arbre_append_mot(arbre,"TRIPE");
    int tab[]={1,0,1,1,1};
    pattern *pat = pattern_from_input(tab,5);
    mot *m = mot_create("TARIF");

    printf("%c\n",arbre->root->head->etiquette);

    printf("Taille : %d\n",taille_noeud(arbre->root));

    printTree(arbre);

    arbre_mots *new_arbre = arbre_update(arbre,m,pat);

    printTree(arbre);

    //printf("%c\n",arbre->root->head->etiquette);

    //printf("%c\n",arbre->root->head->next_node->head->etiquette);
    //printf("%c\n",arbre->root->head->next_node->head->next->etiquette);
    //destroy_arbre(new_arbre);
    destroy_arbre(arbre);
    mot_destroy(m);
    pattern_destroy(pat);

    return EXIT_SUCCESS;
}
