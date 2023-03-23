#include <stdio.h>
#include <stdbool.h>

bool change (char *str) {
  if (str[1] == '\0') return true ;
  for (int i = 1; str[i] != '\0'; i++) {
    if (str[i] != '9') return false ;
  }
  return true ;
}


int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }

  printf ("%d\n", change (argv[1])) ;
  return 0 ;
}
