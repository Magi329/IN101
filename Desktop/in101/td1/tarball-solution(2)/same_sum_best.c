#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* An optional boolean. */
enum bool_option {
  BO_False, /* Boolean false. */
  BO_True,  /* Boolean true. */
  BO_Error  /* Not a boolean value but an error instead. */
};


enum bool_option same_sum (int n, unsigned int c) {
  if (c > 9) return BO_Error ;
  /* Impossible to have a negative sum of positive digits. */
  if (n < 0) return (BO_False) ;
  /* Do not divide by 0. The sum is correct only if it is 0. */
  if (c == 0) return ((n == 0) ? BO_True : BO_False) ;
  return ((n % c == 0) ? BO_True : BO_False) ;  /* Implicitly "else". */
}

int main (int argc, char *argv[]) {
  if (argc != 3) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }

  switch (same_sum (atoi (argv[1]), atoi (argv[2]))) {
  case BO_True : printf ("True\n") ; break ;
  case BO_False : printf ("False\n") ; break ;
  case BO_Error : printf ("Error. Invalid input.\n") ; break ;
  }
  return 0 ;
}
