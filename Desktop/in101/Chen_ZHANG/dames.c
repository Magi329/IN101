/*ZHANG Chen*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Q1.1
1. open the txt document
2. read the size and save it
3. read each element in the table and save it
4. identify the damier
5. saut along the damier and end when there is no more pion
6. print the results

entree: name of the file, x position and y position of the pion we want to test
sortie: string that indicates the number of moves or impossible to move

Q1.2
chargement de damier

entree: nom du fichier
sortie: un tableau

1. read the size
2. create the
3. read each element of the table and save




Q1.3
nombre maximal de saut = taille du damier*2

Q1.4
for each step of the saut,
        1 detect the immediate surrounding pion(the former direction not included)
            if no more available pion, return to the former position and try other directions
        2 find the vide case in the same direction of the detected poin
            if no more available pion, return to the former position and try other directions
        3 make radume choice of the saut among the vide case
                then begin another saut
            

*/

int* explore_pion_imm(int size, char* T, int x, int y, int former_dir){
    int* poin_imm = malloc(sizeof(int)*4);

    //en haut
    if(T[(x-1)*size + y]==1 && x>0) poin_imm[0] = 1;
    else poin_imm[0] = 0;

    //en bas
    if(T[(x+1)*size + y]==1 && x<size-1) poin_imm[1] = 1;
    else poin_imm[1] = 0;

    //a gauche
    if(T[x*size + y-1]==1 && y>0) poin_imm[2] = 1;
    else poin_imm[2] = 0;

    //a droit
    if(T[x*size + y+1]==1 && x<size-1) poin_imm[3] = 1;
    else poin_imm[3] = 0;

    
    poin_imm[former_dir] = 0;
    return poin_imm;
    }

int* verifiy_vide(int* poin_imm, int x, int y){
    int* vide = malloc(sizeof(int)*4)
    //on ne va pas vers le haut
    vide[0] = 0;

    //vide = 1 signifie que le poin peut aller
    //vide = 0 signifie que le case est occupe, le poin ne peut pas aller
    if(poin_imm[1] == 1){
        if(T[(x+2)*size + y]==0 && x<size-2) vide[1] = 1;
        else vide[1] = 0;
        }
    if(poin_imm[2] == 1){
        if(T[(x*size + y-2]==0 && y>1) vide[2] = 1;
        else vide[2] = 0;
        }
    if(poin_imm[3] == 1){
        if(T[(x*size + y+2]==0 && y<size-2) vide[3] = 1;
        }

    return vide;
    }

    int saut(int x, int y, int former_dir, int* vide){




    










int main (int argc, char *argv[]) {

    //Q1.2
    FILE *file = fopen (argv[1], "rb") ;
	if (file != NULL){
		int size;
	    char element_lu;
		int compteur=0; // compteur de tour
		fscanf(file,"%d", &size);
		int* T = malloc(sizeof(int)*size*size);
		int* T1 = malloc(sizeof(int)*size*size); // Ce tableau va permettre une vérification plus simple du caractère gagnant
		for (int i=0; i<size*size;i++){ // Remplissage des tableaux
			fscanf(file,"%c", &element_lu);
			T1[i]=0;
            if(strcmp(element_lu,"x")==0) T[i]=1;
            else if(strcmp(element_lu,".")==0) T[i]=0;

			
		}






      return 0 ;
}
