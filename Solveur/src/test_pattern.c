#include "pattern.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int main()
{
    //create pattern from input
    //generate patterns
    //test entropy
    //print pattern
    char *tab = malloc(5*sizeof(char));
    tab[0]='2';
    tab[1]='2';
    tab[2]='0';
    tab[3]='0';
    tab[4]='2';
    int taille =5;
    pattern *p = pattern_from_input(tab,5);
    pattern_print(p);
    pattern **plist = pattern_init_all(taille);
    for (int i = 0; i < pow(3,taille); i++)
    {
        pattern_print(plist[i]);
    }
    for (int i = 0; i < pow(3,taille); i++)
    {
        pattern_destroy(plist[i]);
    }
    free(plist);
    pattern_destroy(p);
    return 0;
}
