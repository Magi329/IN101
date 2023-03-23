#include <stdio.h>
#include <stdlib.h>

/* Factorize to prevent computing the same powers -> 7 operations. */
float poly (float x) {
  return x * (x * (x * (-3 * x + 5)) + 2) + 5 ;
}

int main (int argc, char *argv[]) {
  float x ;
  if (argc != 2) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }
  x = atof (argv[1]) ;
  printf ("poly (%f) = %f\n", x, poly (x)) ;
  return 0 ;
}
