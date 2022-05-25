#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

arbre_mots* arbre_init(int size){
    arbre_mots* arbre=malloc(size*sizeof(arbre_mots));
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
    char* c=fgetc(f);
    while (c!=NULL)
    {
         if (c.strlen()==n){
        arbre_append_mot(arbre,c);
    }
    c=fgetc(f);
    
   

    }
    

}
void arbre_append_mot(arbre_mots* arbre, char* m){
    noeud* current=arbre->root;
    list_ele* currentchar=current->head;
    int i=0;
    while( i<=m.strlen()){
    while (currentchar->next!=NULL)
    {   if (currentchar==NULL){
            currentchar=list_ele_init(m[i]);
            currentchar->next_node=node_init();
            current=currentchar->next_node;
            i++;
        }

        if(currentchar->etiquette==m[i]){
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
            new=list_ele_init(m[i]);
            current->size++;
            new->next_node=node_init();
            current=new->next_node;
            i++;

        
        }
    }
    


}

arbre_mots* arbre_update(arbre_mots* arbre,mot* mots, pattern* pat){
    int n=pat->size;
    char let[n][1]={"",""};
    for (int i=0;i<=pat->size;i++){
        if (pat[i].size==0){
            let[i][1]=mots->val[i];
        }

    }


}
