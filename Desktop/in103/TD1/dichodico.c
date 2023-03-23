/*Chen ZHANG */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "load_dic.h"


//Q7
/*
 comparer l'élément avec la valeur de la case au milieu du tableau ; 
 si les valeurs sont égales, la tâche est accomplie, 
 sinon on recommence dans la moitié du tableau pertinente.

cas de arrêt: EOF or find the word in the dictionnary
traitements annexes
*/


bool find_word_dicho (char **words, char *word, int left, int right){
  int cmp = strcmp(words[(left+right)/2],word);
    while(left<right){
      if(cmp==0) return true;
      else if(cmp<0){//on the right side
        left = (left+right)/2;
        }
      else if(cmp>0){//on the left side
        right = (left+right)/2;
      }
    cmp = strcmp(words[(left+right)/2],word);
    }

  return false; 
}

//Q8
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
    bool res = find_word_dicho(word_array,str,0,size-1);
    if(res==1) printf("Le mot est dans le dictionnaire.\n");
    else if(res==0) printf("Le mot est dans le dictionnaire.\n");
    return 0;
}

 //Q9
/*
    //read the dictionnary
    char** word_array = load_file (argv[1], &size);
    //verify the word
    bool res;
    for(int j=0;j<size;j++){
        res = find_word_dicho(word_array,size,word_array[j]);
        if(res==1) printf("Le mot %s est dans le dictionnaire.\n",word_array[j]);
        else if(res==0) printf("Le mot %s est dans le dictionnaire.\n",word_array[j]);

    }
    
*/


//Q10 complexite O(logn)

