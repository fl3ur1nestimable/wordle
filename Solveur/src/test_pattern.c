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
    int taille = 8;
    int tab[]={0,2,1,0,1};
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
