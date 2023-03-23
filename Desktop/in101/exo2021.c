/* ZHANG Chen */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int find_match(char** grille, int nb){
    int res=-1;
    for

}

void Bingo(char* filename){
    /* open the file*/
    FILE* fp = fopen(filename, "rb");
    if(fp==NULL){
    printf("Error. Un able to open file.\n" );
    return ;
    }

    /* read the size of the table */
    unsigned int size;
    fscanf (fp, "%u", &size);

    /* Create the array of numbers. */
    char** grille = malloc (size * sizeof (char*)) ;
    if (grille == NULL) {
    printf ("Error. Unable to allocate the array of numbers.\n") ;
    fclose (fp) ;
    return ;
    }
{}
    /* Fill the array of numbers. */
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            fscanf(fp, "%d", &grille[i][j]);
        }
    }

    /* read the number list until its end */
    char playList;
    fscanf(fp, "%d", &playList);
    while(!feof(fp)){

    }







}
