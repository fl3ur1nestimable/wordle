#include "pattern.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    //create pattern from input
    //generate patterns
    //test entropy
    //print pattern
    int *tab = malloc(5*sizeof(int));
    tab[0]=2;
    tab[1]=2;
    tab[2]=0;
    tab[3]=0;
    tab[4]=2;
    pattern *p = pattern_from_input(tab,5);
    pattern_print(p);
    pattern_destroy(p);
    return 0;
}