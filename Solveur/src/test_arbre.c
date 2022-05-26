#include "struct.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){

    arbre_mots *arbre = arbre_init();
    lecture_fichier(arbre,5);
    //arbre_append_mot(arbre,"AMOUR");
    //arbre_append_mot(arbre,"AMPOU");
    printf("%c\n",arbre->root->head->etiquette);
    printf("%c\n",arbre->root->head->next_node->head->etiquette);
    //printf("%c\n",arbre->root->head->next_node->head->next_node->head->next->etiquette);
    destroy_arbre(arbre);

    return EXIT_SUCCESS;
}
