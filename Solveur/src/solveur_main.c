#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int base3(int n){
    int r = 0;
    int f = 1;
    int a = n;
    while (a > 0)
    {
        r += (a%3)*f;
        a = a/3;
        f *= 10;
    }
    return r;
 }


bool is_in_possibilities(int proposition, int taille){
    int nbr_possibilites = pow(3,taille);
    int possibilities[nbr_possibilites];
    int i;
    for(i=0;i<nbr_possibilites;i++){
        possibilities[i]=base3(i);
        if(proposition==possibilities[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    int taille;
    int nb_essais;
    printf("Entrez la taille du mot : \n");
    scanf("%d",&taille);
    printf("Entrez le nombre d'essais : \n");
    scanf("%d",&nb_essais);
    int guess[taille];
    int power = pow(3,taille);
    int possibilites[power];
    bool not_win = true;
    int i = nb_essais;


    printf("Vos réponse doivent être de la forme xxx où il y'a autant de x que la taille du mot et où x vaut 0,1, ou 2 \n");
    printf("0 sont les lettres n'étant pas dans le mot, 2 les lettres bien placées et 1 les lettres mal placées \n");
    while(i!=0 && not_win){
        char* mot_propose = "oui"; // cela sera égal à la fonction qui renvoit la meilleure proposition de mots
        printf("%s",mot_propose);
        int somme = 2*taille;
        int result;
        printf("Entrez le résultat pour le mot : \n");
        scanf("%d",&result);
        while(!(is_in_possibilities(result,taille))){
            printf("Votre mot n'est pas dans les possibilités : \nEntrez le résultat pour le mot : \n");
            scanf("%d",&result);
        }
        
        guess[0]=result*pow(10,-(taille-1));
        somme = somme - guess[0];
        int j;
        int a = result;
        for(j=1;j<taille;j++){
            a=a-guess[j-1]*pow(10,taille-j);
            guess[j]=a*pow(10,-(taille-1-j));
            somme = somme - guess[j];
            printf("%d \n",guess[j]);
        }

        // il faut envoyer le tableau guess a la fonction

        i=i-1;

        if(somme == 0){
            printf(" Trouvé ! ");
            not_win = false;
        }
        else{
            printf("Sorry");
        }
    }
    return 0;  
}
