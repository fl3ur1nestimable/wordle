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
list_ele* list_ele_init(char* val){
    list_ele* lettre=malloc(sizeof(list_ele));
    lettre->etiquette=val;
    lettre->next_node=NULL;
    lettre->next=NULL;
    return lettre;
}

void arbre_append(noeud* list, char* val ){
    
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
    f=fopen("../static/liste_mots.txt","rt");
    char* c;
    fgets(c,n,f);
    while (c!=NULL)
    {
         if ((int)strlen(c)==n){
        arbre_append_mot(arbre,c);
    }
    fgets(c,n,f);
    
   

    }
    

}
void arbre_append_mot(arbre_mots* arbre, char* m){
    noeud* current=arbre->root;
    list_ele* currentchar=current->head;
    int i=0;
    while( i<=(int)strlen(m)){
    while (currentchar->next!=NULL)
    {   if (currentchar==NULL){
            currentchar=list_ele_init(&m[i]);
            currentchar->next_node=node_init();
            current=currentchar->next_node;
            i++;
        }

        if(currentchar->etiquette==&m[i]){
            if (currentchar->next_node==NULL)
            {
                currentchar->next_node=node_init();
                current=currentchar->next_node;
                i++;
            }
            else{
                current=currentchar->next_node;
                i++;

            }
        currentchar=currentchar->next;
            

           }
          list_ele* new=currentchar->next;
            new=list_ele_init(&m[i]);
            current->size++;
            new->next_node=node_init();
            current=new->next_node;
            i++;

        
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
    for (int i;i<=(int)strlen(mots->val);i++){
        if (pat->tab[i]==0){
    list_ele* current=node->head;
    char* c=&mots->val[i];
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
void remove_ele(noeud* node, char* c){
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
