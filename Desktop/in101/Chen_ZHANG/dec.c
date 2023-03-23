/*ZHANG Chen*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
first, we decompose the number by 10, and save them in a table
second, we test wether the numbers in the table is descendent by 1
*/


void verify_dec(int nb){
    int i=0;
    int* ans;
    int rest;
    int quotient=nb;
    while(quotient!=0){
        rest = quotient%10;
        quotient = quotient/10;
        ans[i] = rest;
        i++
        }

    
    for(int j=0;j<i-1;j++){
            if(ans[j]+1!=ans[j+1]) printf("Ko\n");
            return ;
        }

    printf("OK\n");
        return ;


}


int main (int argc, char* argv[]) {
    if(argc!=2) printf("False imput\n");
    verify_dec(argv[1]);
    return 0;
    }

