#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nth (char *str, unsigned int index) {
  if (index >= strlen (str))
    printf ("Error. Index out of bounds.\n") ;
  else printf ("%c\n", str[index]) ;
}

int main (int argc, char *argv[]) {
  if (argc != 3) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }
  nth (argv[1], atoi (argv[2])) ;
  return 0 ;
}
