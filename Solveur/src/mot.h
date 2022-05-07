#ifndef MOT_H
#define MOT_H


typedef struct {
    char* val;
    double entropy;
}mot;



mot mot_generate_best(arbre_mots one_arbre);

char* mot_get_val(mot mot);

#endif /* MOT_H */