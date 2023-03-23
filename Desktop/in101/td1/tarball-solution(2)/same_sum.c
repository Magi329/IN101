#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool same_sum (int n, int c) {
  /* Impossible to have a negative sum of positive digits. */
  if (n < 0) return (false) ;
  /* Do not divide by 0. The sum is correct only if it is 0. */
  if (c == 0) {
    if (n == 0) return (true) ;
    else return (false) ;
  }
  else {
    if (n % c == 0) return (true) ;
    else return (false) ;
  }
}

int main (int argc, char *argv[]) {
  if (argc != 3) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }

  printf ("%d\n", same_sum (atoi (argv[1]), atoi (argv[2]))) ;
  return 0 ;
}
