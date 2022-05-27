#include "struct.h"
#include "mot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main(){
    mot *mot1 = mot_create("AMOUR");
    assert(strcmp(mot_get_val(mot1),"AMOUR")==0);
    mot_destroy(mot1);





    /*

    // Création d'un arbre test
    noeud *racine = malloc(sizeof(noeud));
    noeud *noeud_1 = malloc(sizeof(noeud));
    noeud *noeud_2 = malloc(sizeof(noeud));
    noeud *feuille_1 = malloc(sizeof(noeud));
    noeud *feuille_2 = malloc(sizeof(noeud));
    noeud *feuille_3 = malloc(sizeof(noeud));
    noeud *feuille_4 = malloc(sizeof(noeud));
    liste *fils_0 = malloc(sizeof(liste));
    liste *fils_1 = malloc(sizeof(liste));
    liste *fils_2 = malloc(sizeof(liste));
    liste *fils_3 = malloc(sizeof(liste));
    liste *fils_4 = malloc(sizeof(liste));
    liste *fils_5 = malloc(sizeof(liste));
    liste *fils_6 = malloc(sizeof(liste));
    racine->etiquette = 'z';
    noeud_1->etiquette = 'a';
    noeud_2->etiquette = 'e';
    feuille_1->etiquette = 'b';
    feuille_2->etiquette = 'c';
    feuille_3->etiquette = 'd';
    feuille_4->etiquette = 'f';
    racine->next = NULL;
    noeud_1->next = noeud_2; 
    noeud_2->next = NULL;
    feuille_1->next = feuille_4;
    feuille_2->next = feuille_3;
    feuille_3->next = NULL;
    feuille_4->next = NULL;
    
    fils_0->head = noeud_1;
    fils_1->head = feuille_1;
    fils_2->head = feuille_2;
    fils_3->head = NULL;
    fils_4->head = NULL;
    fils_5->head = NULL;
    fils_6->head = NULL;
    racine->liste_fils = fils_0;
    noeud_1->liste_fils = fils_1;
    noeud_2->liste_fils = fils_2;
    feuille_1->liste_fils = fils_3;
    feuille_2->liste_fils = fils_4;
    feuille_3->liste_fils = fils_5;
    feuille_4->liste_fils = fils_6;
    arbre_mots *arbre = malloc(sizeof(arbre_mots));
    arbre->root = racine;

    mot_generate_best(arbre);

    free(fils_0);
    free(fils_1);
    free(fils_2);
    free(fils_3);
    free(fils_4);
    free(fils_5);
    free(fils_6);
    
    free(feuille_4);
    free(feuille_3);
    free(feuille_2);
    free(feuille_1);
    free(noeud_1);
    free(noeud_2);
    free(racine);
    free(arbre);


    //free(mot2);

    */

    return EXIT_SUCCESS;
}

