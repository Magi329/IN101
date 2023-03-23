#include <stdio.h>
#include <stdlib.h>

void nth (char *str, int index) {
  printf ("%c\n", str[index]) ;
}

int main (int argc, char *argv[]) {
  if (argc != 3) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }
  nth (argv[1], atoi (argv[2])) ;
  return 0 ;
}
