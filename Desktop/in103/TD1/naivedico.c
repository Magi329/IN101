/* Chen ZHANG */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "load_dic.h"

/* 
Q1
prendre un fichier, rendre un tableaux de charactaires
 
Q2
pointeurs differents, car adresses differentes
strcmp <=>0 indique ordre dans le dictionnaires
{}
*/

//Q3
bool find_word_naive(char** tableau, unsigned int size, char* mot){
    bool ans = false;

    for(int i=0;i<size;i++){
        if(strcmp(tableau[i],mot)==0){
            ans = true;
            break;
        }
        
    }
    return ans;
}
// complexite :  O(n)

//Q6
/*
On peut chercher chaque mot et vérifier s'il est dans le dictionnaire ou pas
Mais ça va prendre beaucoup de temps, complexite O(n**2)
*/





int main(int argc, char *argv[]){
    if (argc != 2) {
    printf ("Error. Usage: french.txt\n") ;
    return 1 ;
  }
    //read the word
    char str[30];
    printf("Input a word: \n");
    scanf("%s",str);
    //get size
    unsigned int size;
    //read the dictionnary
    char** word_array = load_file (argv[1], &size);
    //verify the word
    bool res = find_word_naive(word_array,size,str);
    if(res==1) printf("Le mot est dans le dictionnaire.\n");
    else if(res==0) printf("Le mot est dans le dictionnaire.\n");
    return 0;

    //Q6
/*
On peut chercher chaque mot et vérifier s'il est dans le dictionnaire ou pas
Mais ça va prendre beaucoup de temps, complexite O(n**2)
*/
/*
    //read the dictionnary
    char** word_array = load_file (argv[1], &size);
    //verify the word
    bool res;
    for(int j=0;j<size;j++){
        res = find_word_naive(word_array,size,word_array[j]);
        if(res==1) printf("Le mot %s est dans le dictionnaire.\n",word_array[j]);
        else if(res==0) printf("Le mot %s est dans le dictionnaire.\n",word_array[j]);

    }
    
*/
}

