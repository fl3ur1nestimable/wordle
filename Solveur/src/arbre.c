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

//Lit le fichier liste_mots.txt et ajoute les mots lu de taille n dans l'arbre
void lecture_fichier(arbre_mots* arbre, int n){
    FILE* f;
    f=fopen("../liste_78k.txt","r");
    char c[20];
   
    
    while (fgets(c,sizeof(c),f)!=NULL)
    {   //printf("%d",(int)strlen(c));
        c[strlen(c)-1]='\0';
        if ((int)strlen(c)==n){
            arbre_append_mot(arbre,c);
        } 
    }
    arbre_init_nb_mots(arbre);
    fclose(f);
    

}

//Ajoute le string m dans l'arbre
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
                current_noeud->next->liste_fils = liste_init();
                current_parent = current_noeud->next;
                current = current_noeud->next->liste_fils;
                i++;
            }
        }
    } 
}

//Enlève la branche associé aux mots générés par le noeud node dans l'arbre 
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
//Met à jour le niveau depth de l'arbre en fonction d'un mot m et d'un patterne pat associé, garde en mémoir le mot parcouru avec str  
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
        case 2:
            // Si le mot ne contient pas la lettre placée à ce niveau, on coupe la branche
            if(i==depth){
                if(node->etiquette!=m->val[i]){
                    noeud_remove(arbre,node);
                    coupe = true;
                    break;
                }else{
                    coupe = false;
                    break;
                }
            }
            break;
        case 0:
            // Si un 0 est au niveau de la lettre, on est sûre de la couper car sinon elle serait un 2
            if(i==depth){
                if(node->etiquette==m->val[i]){
                    noeud_remove(arbre,node);
                    coupe = true;
                    break;
                }
            }
            // Si le mot contient la lettre, on coupe la branche
            if(node->etiquette==m->val[i]){
                if(str_occurences(str,m->val[i])>mot_occurences_pattern(m,pat,m->val[i])){
                    noeud_remove(arbre,node);
                    coupe = true;
                }
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
                if(str_occurences(str,m->val[i])<str_occurences(m->val,m->val[i])){
                    noeud_remove(arbre,node);
                    coupe = true;
                    break;
                }
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
            str[strlen(str)-1]='\0';
            current = next;
        }
    }
    return;
}
//Met à jour l'arbre en fonction d'un mot m et d'un patterne pat associé cad coupe les branches générant les mots impossible avec le patterne
void arbre_update(arbre_mots* arbre,mot* m, pattern* pat){
    char str[12]="A";
    noeud *current = arbre->root->head;
    while(current!=NULL){
        noeud *next = current->next;
        noeud_update(arbre,current,m,pat,0,str);
        current=next;
        str[strlen(str)-1]='\0';
    }
    arbre_init_nb_mots(arbre);
    return;
}


//Free les allocations mémoires de l'arbre
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
//Free les allocations mémoires du noeud node
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

// Renvoie le nombre de noeud dans l'arbre
int arbre_taille(arbre_mots *arbre){
    int taille = 0;
    noeud *current = arbre->root->head;
    while(current!=NULL){
        taille += noeud_taille(current);
        current = current->next;
    }
    return taille;
}
int noeud_taille(noeud *node){
    if(node == NULL){
        return 0;
    }
    int taille = 1;
    //Parcours des descendants
    noeud *current = node->liste_fils->head;
    while(current!=NULL){
        taille += noeud_taille(current);
        current = current->next;
    }
    return taille;
}

// Print l'arbre avec ses noeuds et le nb_mots générés à partir du noeud de manière verticale
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
        printf("+--- %c",n->etiquette);
        printf("_%d\n",n->nb_mots);
    }
    // Condition when the l is
    // the last l of
    // the exploring depth
    else if (isLast) {
        printf("+--- %c_%d\n",n->etiquette, n->nb_mots);
        
        // No more childrens turn it
        // to the non-exploring depth
        flag[depth] = false;
    }
    else {
        printf("+--- %c_%d\n",n->etiquette,n->nb_mots);
    }
    noeud *current = n->liste_fils->head;
    while(current!=NULL){
        printNTree(current,flag,depth+1,current->next==NULL);
        current = current->next;
    }
    flag[depth] =true;
    
}
void printTree(arbre_mots *arbre){
    int n = arbre_taille(arbre);
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

//Initialise les variables nb_mots dans l'arbre et ses noeuds au nombre de mot généré à partir de l'arbre (noeuds) cad le nombre de feuilles
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
    node->nb_mots = count;
    return count;
}

//Renvoie la probabilité que le mot se trouve dans l'arbre après update de l'arbre en fonction de l'association du mot m et du pattern one_pattern
double arbre_proba(arbre_mots* arbre, mot* m, pattern* one_pattern){
    int nb_mots_init = arbre->nb_mots;
    int nb_mots_apres_coupure = arbre_nb_mot(arbre,m,one_pattern);
    return (double)nb_mots_apres_coupure/nb_mots_init; 
}

// Renvoie le nombre de mots enlevés dans l'arbre si on le mettait à jour avec l'association du mot m et du pattern p / Garde en mémoire la profondeur de l'arbre parcouru (depth) et le mot parcouru (str)
int noeud_nb_mot_coupe(noeud *node,mot *m,pattern *pat,int depth,char *str){
    if(depth>pat->size){
        return 0;
    }
    int count = 0;
    str[depth]=node->etiquette;
    //printf("-%s\n",str);
    bool coupe = false;
    for(int i=0;i<pat->size;i++){
        if(coupe){
            break;
        }
        switch (pat->tab[i])
        {
        case 2:
            // Si le mot ne contient pas la lettre placée à ce niveau, on coupe
            if(i==depth){
                if((node->etiquette!=m->val[i])){
                coupe = true;
                count += node->nb_mots;
            }else{
                coupe = false;
            }
            break;
            }
        case 0:
            if(i==depth){
                if(node->etiquette==m->val[i]){
                    count += node->nb_mots;;
                    coupe = true;
                    break;
                }
            }
            // Si le mot contient la lettre, on coupe la branche
            if(node->etiquette==m->val[i]){
                if(str_occurences(str,m->val[i])>mot_occurences_pattern(m,pat,m->val[i])){
                    count += node->nb_mots;;
                    coupe = true;
                }
            }
            break;
        case 1:
            // Si le mot contient la lettre placée à ce niveau, on coupe
            if((node->etiquette==m->val[i])&&(i==depth)){
                coupe = true;
                count += node->nb_mots;
                break;
            }
            // Si c'est une feuille, on a atteint la fin du mot, on vérifie avec les occurences si le mot contient le bon nb de lettres
            if(node->liste_fils->head==NULL){
                // Si on a trouvé moins de lettres(associé au 1) dans le mot, on l'enlève 
                if(str_occurences(str,m->val[i])<str_occurences(m->val,m->val[i])){
                    count += 1;
                    coupe = true;
                }
    
            }
            break;
        default:
            break;
        }
    }
    // Si on a pas coupé la branche, on continue de parcourir les branches suivante (liste fils et niveau suivant)
    if(!coupe){
        noeud *current = node->liste_fils->head;
        while(current!=NULL){
            noeud *next = current->next;
            count += noeud_nb_mot_coupe(current,m,pat,depth+1,str);
            str[strlen(str)-1]='\0';
            current = next;
        }
    }
    // On retourne le nombre de mots qu'on a enlevé
    return count;

}
int arbre_nb_mot(arbre_mots *arbre, mot *m, pattern *pat){
    char str[12] = "";
    int nb_mots_coupe = 0;
    noeud *current = arbre->root->head;
    while(current!=NULL){
        nb_mots_coupe += noeud_nb_mot_coupe(current,m,pat,0,str);
        current = current->next;
        str[strlen(str)-1]='\0';
    }
    return arbre->nb_mots-nb_mots_coupe;

}

// Renvoie un booléen true si le noeud node est une feuille, false sinon
bool noeud_est_feuille(noeud *n){
    return n->liste_fils->head==NULL;
}
// Renvoie un booléen true si la liste l est vide, false sinon
bool liste_est_vide(liste *l){
    return l->head==NULL;
}





