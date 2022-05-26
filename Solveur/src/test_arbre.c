#include "struct.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){

    arbre_mots *arbre = arbre_init();
    arbre_append_mot(arbre,"AMOUR");
    //printf("%c\n",arbre->root->head->etiquette);
    //printf("%c\n",arbre->root->head->next_node->head->etiquette);
    destroy_arbre(arbre);

    return EXIT_SUCCESS;
}
