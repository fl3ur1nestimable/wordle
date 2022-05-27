#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arbre_mots* arbre_init(){
    arbre_mots* arbre=malloc(sizeof(arbre_mots));
    arbre->root=node_init();
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
    lettre->next_node=node_init();
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
    f=fopen("../static/liste_test.txt","r");
    char c[20];
   
    
    while (fgets(c,sizeof(c),f)!=NULL)
    {   //printf("%d",(int)strlen(c));
        c[strlen(c)-1]='\0';
        printf("%d\n",(int)strlen(c));
        if ((int)strlen(c)==n){
            arbre_append_mot(arbre,c);
        } 
    printf("%s",c);
   

    }
    fclose(f);
    

}
void arbre_empty_append(arbre_mots* arbre,char* c){
    noeud* current=arbre->root;
    for (int i=0;i<(int)strlen(c);i++){
       list_ele* ch=list_ele_init(c[i]);
        current->head=ch;
        printf("%c",arbre->root->head->etiquette);
        current=current->head->next_node;
    }
}

void arbre_append_mot(arbre_mots* arbre, char* m){
    if (arbre->root->head==NULL){
        printf("%d",0);
        arbre_empty_append(arbre,m);
    }
    noeud* current=arbre->root;
    list_ele* currentchar=arbre->root->head;
    int i=0;
    while( i<=(int)strlen(m)){
        while (currentchar->next!=NULL)
        {   
            if (currentchar==NULL){
                    currentchar=list_ele_init(m[i]);
                    currentchar->next_node=node_init();
                    current=currentchar->next_node;
                    i+=1;
                    printf("%c\n",currentchar->etiquette);
            }

        if(currentchar->etiquette==m[i]){
            if (currentchar->next_node==NULL)
            {
                currentchar->next_node=node_init();
                current=currentchar->next_node;
                printf("%c\n",currentchar->etiquette);
                i+=1;
            }
            else{
                current=currentchar->next_node;
                printf("%c\n",currentchar->etiquette);
                i+=1;

            }
        currentchar=currentchar->next;
            

           }
        }
        list_ele* new=currentchar->next;
        new=list_ele_init(m[i]);
        current->size++;
        new->next_node=node_init();
        current=new->next_node;
        i+=1;
        printf("%c\n",currentchar->etiquette);
    }
    
}
int taille_noeud(noeud* node){
list_ele* current=node->head;
    if (current->next_node==NULL){
        return node->size;

    }
    
    int p=0;
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
