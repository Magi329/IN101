#include <stdio.h>
#include <stdlib.h>

int sum (int x, int y) {
  int accu = 0 ;
  int start = x ;
  int stop = y ;
  int i ;

  /* Check which argument is the smallest to start from it. */
  if (y < x) {
    start = y ;
    stop = x ;
  }

  for (i = start; i <= stop; i++) {
    if ((i % 5 == 0) && (i % 2 != 0)) accu = accu + i ;
  }
  return accu ;
}

int main (int argc, char *argv[]) {
  if (argc != 3) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }
  printf ("%d\n", sum (atoi (argv[1]), atoi (argv[2]))) ;
  return 0 ;
}
