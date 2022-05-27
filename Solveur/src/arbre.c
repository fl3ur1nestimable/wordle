#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

arbre_mots* arbre_init(){
    arbre_mots* arbre=malloc(sizeof(arbre_mots));
    arbre->root=NULL;
    return arbre;
    
}

noeud* node_init(){
    noeud* L=malloc(sizeof(noeud));
    L->head=NULL;
    
    L->size=0;
    return L;

}
list_ele* list_ele_init(char val){
    list_ele* lettre=malloc(sizeof(list_ele));
    lettre->etiquette=val;
    lettre->next_node=NULL;
    lettre->next=NULL;
    return lettre;
}

void arbre_append(noeud* list, char val ){
    
    list_ele* current =list->head;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=list_ele_init(val);
    list->size++;
    


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
    // Si l'arbre est vide, on l'initialise
    if(arbre->root==NULL){
        arbre->root=node_init();
    }
    // Initialisation du compteur niveau
    int i = 0;
    // 
    noeud* current=arbre->root;

    while( i<(int)strlen(m)){
        //printf("%d ",i);
        //printf("%c\n",m[i]);
        // Si la liste de noeuf est vide 
        //printf("%d\n",current->head==NULL);
        if(current->head==NULL){
            //printf("feuille\n");
            current->head=list_ele_init(m[i]);
            current->size ++;
            current->head->next_node=node_init();
            current = current->head->next_node;
            i++;
        }else{
            list_ele *current_ele = current->head;
            // Tant que la liste n'est pas vide, on parcoure la liste
            while(current_ele->next!=NULL){
                // Si la lettre existe déjà, on passe au niveau suivant
                if(current_ele->etiquette==m[i]){
                    break;
                }
                current_ele = current_ele->next;
            }
            if(current_ele->etiquette==m[i]){
                current = current_ele->next_node;
                i++;
            }else{
                // On ajoute a la fin de la liste
                current_ele->next=list_ele_init(m[i]);
                current->size ++;
                current_ele->next->next_node = node_init();
                current = current_ele->next->next_node;
                i++;
            }
        }

    }
  
}
int taille_noeud(noeud* node){
    if (node==NULL){
        return 0;
    }
    list_ele* current=node->head;
    if (current==NULL){
        return 0;
    }
    
    int p=node->size;
    while (current!=NULL){
        p+=taille_noeud(current->next_node);
        current=current->next;
    }
    return p;
}

int taille_arbre(arbre_mots* arbre){
    return taille_noeud(arbre->root);
}

noeud* node_update(noeud* node, mot* mots, pattern* pat){
    for (int i=0;i<(int)strlen(mots->val);i++){
        if (pat->tab[i]==0){
            list_ele* current=node->head;
            char c=mots->val[i];
            bool node_detruite = remove_ele(node,c);
            if(node_detruite){
                return NULL;
            }
            current=node->head;
            while (current!=NULL){
                node_detruite = remove_ele(current->next_node,c);
                current=current->next;
            }
        }
    }
    return node;
}
arbre_mots* arbre_update(arbre_mots* arbre,mot* mots, pattern* pat){
    //arbre_mots *new_arbre=arbre_init();
    //memcpy(new_arbre,arbre,sizeof(arbre_mots));
    arbre->root = node_update(arbre->root,mots,pat);
    return arbre;
}
bool remove_ele(noeud* node, char c){
    list_ele* current=node->head;
    // Si c'est la tête qu'on enlève
    if (current->etiquette==c){
        // Si c'était le seul élément de la liste
        if(current->next==NULL){
            destroy_node(node);
            return true;
        }
        list_ele *temp = current->next;
        destroy_node(current->next_node);
        free(current);
        node->size--;
        // On modifie la tête de la node
        node->head=temp;
        return false;
    }

    while ((current->next!=NULL)&&(current->next->etiquette!=c)){
        current=current->next;
    }

    if (current->next->etiquette==c){
        list_ele *temp = current->next->next;
        destroy_node(current->next->next_node);
        free(current->next);
        current->next = temp;
        node->size--;
    }
    return false;
    
}
void remove_node(noeud* node){
    if (node==NULL){
        return;
    }
    list_ele* current=node->head;
    free(node);
    while (current->next!=NULL)
    {   remove_node(current->next_node);
        free(current);
        current=current->next;
        
    }

}

void destroy_node(noeud *node){
    if (node==NULL){
        return;
    }
    if(node->head==NULL){
        free(node);
        return;
    }
    list_ele *current_ele = node->head;
    while(current_ele!=NULL){
        list_ele *temp = current_ele->next;
        destroy_node(current_ele->next_node);
        free(current_ele);
        current_ele = temp;
    }
    free(node);
}

void destroy_arbre(arbre_mots *arbre){
    if(arbre->root==NULL){
        free(arbre);
        return;
    }
    noeud *current = arbre->root;
    destroy_node(current);
    free(arbre);
}

/*
noeud *node_cpy(noeud *node){
    if(node==NULL){
        return NULL;
    }
    if(node->head==NULL){
        return NULL;
    }
    node_cpy(node->head->next)
}

arbre_mots *arbre_cpy(arbre_mots *arbre){
    arbre_mots *new_arbre = arbre_init();
    noeud *root = node_cpy(arbre->root); 
    new_arbre->root = root;
}

*/


void printNTree(noeud* n, bool flag[], int depth, bool isLast)
{
    // Condition when node is None
    if (n->head == NULL){
        //printf("7");
        return;
    }
    list_ele *current_ele = n->head;
    while(current_ele!=NULL){
        // Loop to print the depths of the
        // current node
        for (int i = 1; i < depth; ++i) {
            
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
        // node is the root node
        if (depth == 1){
            printf("+--- %c\n",current_ele->etiquette);
        }
        // Condition when the node is
        // the last node of
        // the exploring depth
        else if (isLast) {
            printf("+--- %c \n",current_ele->etiquette);
            
            // No more childrens turn it
            // to the non-exploring depth
            flag[depth] = false;
        }
        else {
            //printf("5");
            printf("+--- %c\n",current_ele->etiquette);
        }
        noeud *current = current_ele->next_node;
        printNTree(current,flag,depth+1,current_ele->next==NULL);
        //printf("0-");
        //printf("%d\n",depth);
        current_ele = current_ele->next;
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
    printNTree(arbre->root,flag,1,false);
}


