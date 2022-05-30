#include "struct.h"
#include "mot.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main(){
    mot *mot1 = mot_create("AMOUR");
    arbre_mots *arbre = arbre_init();
    lecture_fichier(arbre,5);

    mot_destroy(mot1);

    return EXIT_SUCCESS;
}

