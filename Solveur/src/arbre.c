#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char* c = malloc(sizeof(char));
    while (fgets(c,sizeof(c),f)!=NULL){
        if ((int)strlen(c)==n){
            //arbre_append_mot(arbre,c);
            printf("%s",c);
        }
    }

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
        printf("%d",i);
        printf("%c\n",m[i]);
        // Si la liste de noeuf est vide 
        if(current->head==NULL){
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
                    current = current->head->next_node;
                    i++;
                    break;
                }
                current_ele = current_ele->next;
            }
            // On rajoute le noeud à la fin de la liste
            current_ele->next=list_ele_init(m[i]);
            current->size ++;
            current_ele->next_node = node_init();
            current = current_ele->next->next_node;
        }

    }
  
}
int taille_noeud(noeud* node){
list_ele* current=node->head;
    if (current==NULL){
        return 0;

    }
    if (node==NULL)
    {
        return 0;
    }
    
    int p=node->size;
    while (current->next!=NULL)
    {
            p+=taille_noeud(current->next_node);
            current=current->next;
    }
    return p;
}

int taille_arbre(arbre_mots* arbre){
    noeud* current=arbre->root;
    return taille_noeud(current);
}

noeud* node_update(noeud* node, mot* mots, pattern* pat){
    for (int i=0;i<=(int)strlen(mots->val);i++){
        if (pat->tab[i]==0){
    list_ele* current=node->head;
    char c=mots->val[i];
    remove_ele(node,c);
    while (current->next!=NULL){
        remove_ele(current->next_node,c);
        current=current->next;

    }
}
}
return node;
}
arbre_mots* arbre_update(arbre_mots* arbre,mot* mots, pattern* pat){
    noeud* node=arbre->root;
    node_update(node,mots,pat);
    return arbre;
}
void remove_ele(noeud* node, char c){
    list_ele* current=node->head;
    list_ele* cur2=current->next;
    while (current->next!=NULL)
    {
        if (cur2->etiquette==c){
            current->next=cur2->next;
            free(cur2);
            cur2=cur2->next;
            node->size--;

        }
        current=current->next;
        cur2=cur2->next;
    }
    
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
