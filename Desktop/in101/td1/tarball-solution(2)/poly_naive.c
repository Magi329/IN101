#include <stdio.h>
#include <stdlib.h>

/* 5x^3 + 2x - 3x^4 + 5 -> 11 operations. */
float poly (float x) {
  return 5 * x * x * x + 2 * x - 3 * x * x * x * x + 5 ;
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
