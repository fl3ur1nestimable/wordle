#include "arbre.h"
#include "mot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

arbre_mots* arbre_init(){
    arbre_mots* arbre=malloc(sizeof(arbre_mots));
    arbre->root=liste_init();
    return arbre;   
}
liste* liste_init(){
    liste* new_list=malloc(sizeof(liste));
    new_list->head=NULL;
    new_list->nb_mots = 0;
    new_list->size=1;
    return new_list;

}
noeud* noeud_init(char val,noeud *prev,noeud *parent){
    noeud* new_noeud=malloc(sizeof(noeud));
    new_noeud->etiquette=val;
    new_noeud->liste_fils=NULL;
    new_noeud->next=NULL;
    new_noeud->prev=prev;
    new_noeud->parent=parent;
    new_noeud->nb_mots=0;
    return new_noeud;
}

void lecture_fichier(arbre_mots* arbre, int n){
    FILE* f;
    f=fopen("../liste_mots.txt","r");
    char c[20];
   
    
    while (fgets(c,sizeof(c),f)!=NULL)
    {   //printf("%d",(int)strlen(c));
        c[strlen(c)-1]='\0';
        if ((int)strlen(c)==n){
            arbre_append_mot(arbre,c);
        } 
    }
    fclose(f);
    

}

void arbre_append_mot(arbre_mots* arbre, char* m){
    // Initialisation du compteur niveau
    int i = 0;
    // 
    liste* current=arbre->root;
    noeud* current_parent=NULL;
    while( i<(int)strlen(m)){
        // Si la liste de noeud est vide on ajoute le nv noeud à la liste 
        if(current->head==NULL){
            current->head=noeud_init(m[i],NULL,current_parent);
            current->size ++;
            current->head->liste_fils=liste_init();
            current_parent = current->head;
            current = current->head->liste_fils;
            i++;
        }else{
            noeud *current_noeud = current->head;
            // Tant que la liste n'est pas vide, on parcoure la liste
            while(current_noeud->next!=NULL){
                // Si la lettre existe déjà, on passe au niveau suivant
                if(current_noeud->etiquette==m[i]){
                    break;
                }
                current_noeud = current_noeud->next;
            }
            if(current_noeud->etiquette==m[i]){
                current_parent = current_noeud;
                current = current_noeud->liste_fils;
                i++;
            }else{
                // On ajoute a la fin de la liste
                current_noeud->next=noeud_init(m[i],current_noeud,current_parent);
                current->size ++;
                current_noeud->next->liste_fils = liste_init();
                current_parent = current_noeud->next;
                current = current_noeud->next->liste_fils;
                i++;
            }
        }

    } 
}

int taille_liste(liste* l){
    if (l==NULL){
        return 0;
    }

    noeud* current=l->head;
    if (current==NULL){
        return 0;
    }
    int p=l->size;
    while (current!=NULL){
        p+=taille_liste(current->liste_fils);
        current=current->next;
    }
    return p;
}
int taille_arbre(arbre_mots* arbre){
    return taille_liste(arbre->root);
}

void liste_update(liste *l,mot *m, pattern *pat,int depth,char* str){
    if(depth>pat->size){
        return ;
    }
    noeud *current_noeud = l->head;
    while(current_noeud!=NULL){
        //printf("%c\n",current_noeud->etiquette);
        str[depth]=current_noeud->etiquette;
        bool coupe = false;
        bool l_detruite = false;
        bool change_pointeur = true;
        for(int i=0;i<pat->size;i++){
            if(coupe){
                break;
            }
            switch (pat->tab[i])
            {
            case 0:
                // Si le mot contient la lettre, on coupe
                if(current_noeud->etiquette==m->val[i]){
                    noeud *temp = current_noeud->prev;
                    l_detruite = liste_remove_noeud(l,current_noeud);
                    coupe = true;
                    if(l_detruite){
                        return;
                    }
                    // Si c'est la tête qu'on a enlevé, on modifie le pointeur
                    if(temp==NULL){
                        current_noeud = l->head;
                        change_pointeur = false;
                    // Sinon on pointe vers le précédent
                    }else{
                        current_noeud = temp;
                    }
                }
                break;
            case 2:
                // Si le mot ne contient pas la lettre placée à ce niveau, on coupe
                if((i==depth)&&(current_noeud->etiquette!=m->val[i])){
                    noeud *temp = current_noeud->prev;
                    l_detruite = liste_remove_noeud(l,current_noeud);
                    coupe = true;
                    if(l_detruite){
                        return;
                    }
                    // Si c'est la tête qu'on a enlevé
                    if(temp==NULL){
                        current_noeud = l->head;
                        change_pointeur = false;
                    // Sinon on recolle le précédent avec le suivant
                    }else{
                        current_noeud = temp;
                    }
                }
                break;
            case 1:
                // Si le mot contient la lettre placée à ce niveau, on coupe
                if((current_noeud->etiquette==m->val[i])&&(i==depth)){
                    noeud *temp = current_noeud->prev;
                    l_detruite = liste_remove_noeud(l,current_noeud);
                    coupe = true;
                    if(l_detruite){
                        return;
                    }
                    // Si c'est la tête qu'on a enlevé
                    if(temp==NULL){
                        current_noeud = l->head;
                        change_pointeur = false;
                    // Sinon on recolle le précédent avec le suivant
                    }else{
                        current_noeud = temp;
                    }
                }
                // Si c'est une feuille, on a atteint la fin du mot, on vérifie avec les occurences si le mot contient le bon nb de lettres
                if(current_noeud->liste_fils->head==NULL){
                    // Si on a trouvé moins de lettres(associé au 1) dans le mot, on l'enlève 
                    if(mot_occurences(str,m->val[i])<mot_occurences(m->val,m->val[i])){
                        noeud *temp = current_noeud->prev;
                        l_detruite = liste_remove_noeud(l,current_noeud);
                        coupe = true;
                        if(l_detruite){
                            return;
                        }
                        // Si c'est la tête qu'on a enlevé
                        if(temp==NULL){
                            current_noeud = l->head;
                            change_pointeur = false;
                        // Sinon on recolle le précédent avec le suivant
                        }else{
                            current_noeud = temp;
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        // Si on a pas coupé la branche, on continue de parcourir la branche suivante (liste suivant et niveau suivant)
        if(!coupe){
            liste_update(current_noeud->liste_fils,m,pat,depth+1,str);
        }
        // On éxécute le programme pour chaque élément de la liste 
        if(change_pointeur){
            current_noeud = current_noeud->next;
        }
    }
    // On retourne le nombre de mots qu'on a enlevé
    return;
}
void noeud_remove(arbre_mots *arbre, noeud *node){
    if(node==NULL){
        return;
    }
    noeud *prev = node->prev;
    noeud *next = node->next;
    noeud *parent = node->parent;
    // Si c'est le seul élément de sa liste
    if(prev==NULL&&next==NULL){
        noeud *current = node->liste_fils->head;
        while(current!=NULL){
            noeud *next = current->next;
            noeud_destroy(current);
            current = next;
        }
        free(node->liste_fils);
        free(node);
        parent->liste_fils->head=NULL;
        noeud_remove(arbre,parent);
        return;
    }
    // Si c'est la tête de liste qu'on enlève, on update la head de la liste
    if(prev==NULL){
        if(parent==NULL){
            arbre->root->head=next;
        }else{
            parent->liste_fils->head=next;
        }
    }
    // Recollage
    if(prev!=NULL){
        prev->next=next;
    }   
    if(next!=NULL){
        next->prev=prev;
    }
    // Supression de ses descendants
    noeud *current = node->liste_fils->head;
    while(current!=NULL){
        noeud *next = current->next;
        noeud_destroy(current);
        current = next;
    }
    free(node->liste_fils);
    free(node);
    return;
}
void noeud_update(arbre_mots *arbre,noeud *node,mot *m, pattern* pat, int depth,char* str){
    if(node==NULL){
        return;
    }
    str[depth]=node->etiquette;
    bool coupe = false;
    for(int i=0;i<pat->size;i++){
        if(coupe){
            break;
        }
        switch (pat->tab[i])
        {
        case 0:
            // Si le mot contient la lettre, on coupe la branche
            if(node->etiquette==m->val[i]){
                noeud_remove(arbre,node);
                coupe = true;
            }
            break;
        case 2:
            // Si le mot ne contient pas la lettre placée à ce niveau, on coupe la branche
            if((i==depth)&&(node->etiquette!=m->val[i])){
                noeud_remove(arbre,node);
                coupe = true;
            }
            break;
        case 1:
            // Si le mot contient la lettre placée à ce niveau, on coupe la branche
            if((node->etiquette==m->val[i])&&(i==depth)){
                noeud_remove(arbre,node);
                coupe = true;
                break;
            }
            // Si c'est une feuille, on a atteint la fin du mot, on vérifie avec les occurences si le mot contient le bon nb de lettres
            if(noeud_est_feuille(node)){
                // Si on a trouvé moins de lettres(associé au 1) dans le mot, on l'enlève 
                if(mot_occurences(str,m->val[i])<mot_occurences(m->val,m->val[i])){
                    noeud_remove(arbre,node);
                    coupe = true;
                }
            return;
            }
            break;
        default:
            break;
        }
    }
    // On procède aux appels récursifs sur les fils
    //printf("-%c\n",node->etiquette);
    if(!coupe){
        noeud *current = node->liste_fils->head;
        while(current!=NULL){
            noeud *next = current->next;
            noeud_update(arbre,current,m,pat,depth+1,str);
            current = next;
        }
    }
    return;
}
void arbre_update(arbre_mots* arbre,mot* m, pattern* pat){
    char str[12];
    noeud *current = arbre->root->head;
    while(current!=NULL){
        noeud *next = current->next;
        noeud_update(arbre,current,m,pat,0,str);
        current=next;
    }
    return;
}
bool liste_remove_noeud(liste* l, noeud *current){
    noeud *prev = current->prev;
    noeud *next = current->next;
    // Si c'est le seul élément de sa l
    if(prev==NULL&&next==NULL){
        l->head=NULL;
        l->size=0;
        free(current);
        return true;
    }
    // Si c'est la tête qu'on enlève
    if (prev==NULL){
        l->head=next;
    }
    // Recollage
    if(prev!=NULL){
        prev->next=next;
    }   
    if(next!=NULL){
        next->prev=prev;
    }
    //destroy_liste(current->liste_fils);
    l->size--;
    free(current);
    return false;
    
}

void arbre_destroy(arbre_mots *arbre){
    if(arbre->root==NULL){
        free(arbre);
        return;
    }
    noeud *current = arbre->root->head;
    while(current!=NULL){
        noeud *next = current->next;
        noeud_destroy(current);
        current = next;
    }
    free(arbre->root);
    free(arbre);
}
void noeud_destroy(noeud *node){
    if(node == NULL){
        return;
    }
    noeud *current = node->liste_fils->head;
    while(current!=NULL){
        noeud *next = current->next;
        noeud_destroy(current);
        current = next;
    }
    free(node->liste_fils);
    free(node);
}

void printNTree(noeud* n, bool flag[], int depth, bool isLast)
{
    // Condition when node is None
    if (n == NULL){
        return;
    }
    // Loop to print the depths of the
    // current l
    for (int i = 0; i < depth; ++i) {
        
        // Condition when the depth
        // is exploring
        if (flag[i] == true) {
            printf("|    ");
        }
        
        // Otherwise print
        // the blank spaces
        else {
            printf("     ");
        }
    }
    
    // Condition when the current
    // l is the root l
    if (depth == 0){
        printf("+--- %c\n",n->etiquette);
    }
    // Condition when the l is
    // the last l of
    // the exploring depth
    else if (isLast) {
        printf("+--- %c \n",n->etiquette);
        
        // No more childrens turn it
        // to the non-exploring depth
        flag[depth] = false;
    }
    else {
        printf("+--- %c\n",n->etiquette);
    }
    noeud *current = n->liste_fils->head;
    while(current!=NULL){
        printNTree(current,flag,depth+1,current->next==NULL);
        current = current->next;
    }
    flag[depth] =true;
    
}
void printTree(arbre_mots *arbre){
    int n = taille_arbre(arbre);
    bool flag[n];
    //flag[0]=false;
    for(int k=0;k<n;k++){
        flag[k]=true;
    }
    printf("\n---------- Arbre ----------\n");
    noeud *current = arbre->root->head;
    while(current!=NULL){
        printNTree(current,flag,0,current->next==NULL);
        current = current->next;
    }
}


void arbre_init_nb_mots(arbre_mots *arbre){
    int count = 0;
    noeud *current = arbre->root->head;
    while(current!=NULL){
        count += noeud_init_nb_mots(current);
        current = current->next;
    }
    arbre->nb_mots = count;
    return;
}
int noeud_init_nb_mots(noeud *node){
    // Cas de base -- 1 Feuille = 1 Mot
    if(noeud_est_feuille(node)){
        node->nb_mots=1;
        return 1;
    }
    int count = 0;
    noeud *current = node->liste_fils->head;
    // Somme des nb mots de ses descendants
    while(current!=NULL){
        count += noeud_init_nb_mots(current);
        current = current->next;
    }
    return count;
}

double proba(arbre_mots* arbre, mot* mot, pattern* one_pattern){
    int nb_mots_init = arbre->nb_mots;
    int tab[one_pattern->size];
    for(int k=0;k<one_pattern->size;k++){
        tab[k]=0;
    }
    char str[12] = "";
    int nb_mots_coupes = nb_mots_pat(arbre->root,mot, one_pattern,0,str);
    int nb_mots_apres_coupure = nb_mots_init - nb_mots_coupes;
    //printf("Nombre de mots coupés : %d\n",nb_mots_coupes);
    return (double)nb_mots_apres_coupure/nb_mots_init; 
}

int nb_mots_pat(liste *l,mot *m, pattern *pat,int depth,char* str){
    if(depth>pat->size){
        return 0;
    }
    int count = 0;
    noeud *current_noeud = l->head;
    while(current_noeud!=NULL){
        //printf("%c\n",current_noeud->etiquette);
        str[depth]=current_noeud->etiquette;
        bool coupe = false;
        for(int i=0;i<pat->size;i++){
            if(coupe){
                break;
            }
            switch (pat->tab[i])
            {
            case 0:
                // Si le mot contient la lettre, on coupe
                if(current_noeud->etiquette==m->val[i]){
                    count += current_noeud->liste_fils->nb_mots;
                    coupe = true;
                }
                break;
            case 2:
                // Si le mot ne contient pas la lettre placée à ce niveau, on coupe
                if((current_noeud->etiquette!=m->val[i])&&(i==depth)){
                    coupe = true;
                    count += current_noeud->liste_fils->nb_mots;
                }
                break;
            case 1:
                // Si le mot contient la lettre placée à ce niveau, on coupe
                if((current_noeud->etiquette==m->val[i])&&(i==depth)){
                    coupe = true;
                    count += current_noeud->liste_fils->nb_mots;
                    break;
                }
                // Si c'est une feuille, on a atteint la fin du mot, on vérifie avec les occurences si le mot contient le bon nb de lettres
                if(current_noeud->liste_fils->head==NULL){
                    // Si on a trouvé moins de lettres(associé au 1) dans le mot, on l'enlève 
                    if(mot_occurences(str,m->val[i])<mot_occurences(m->val,m->val[i])){
                        count += 1;
                    }
        
                }
                break;
            default:
                break;
            }
        }
        // Si on a pas coupé la branche, on continue de parcourir la branche suivante (liste suivant et niveau suivant)
        if(!coupe){
            count += nb_mots_pat(current_noeud->liste_fils,m,pat,depth+1,str);
        }
        // On éxécute le programme pour chaque élément de la liste 
        current_noeud = current_noeud->next;
    }
    // On retourne le nombre de mots qu'on a enlevé
    return count;
}

bool noeud_est_feuille(noeud *n){
    return n->liste_fils->head==NULL;
}
bool liste_est_vide(liste *l){
    return l->head==NULL;
}





