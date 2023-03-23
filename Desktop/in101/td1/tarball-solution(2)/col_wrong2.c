#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool col (float xa, float ya, float xb, float yb, float xc, float yc) {
  float left = (xb - xa) * (yc - yb) ;
  float right = (xc - xb) * (yb - ya) ;
  float delta = left - right ;
  return (delta == 0) ;
}

int main (int argc, char *argv[]) {
  if (argc != 7) {
    printf ("Error. Wrong number of arguments.\n") ;
    return 1 ;
  }

  if (col (atof (argv[1]), atof (argv[2]), atof (argv[3]),
               atof (argv[4]), atof (argv[5]), atof (argv[6])))
    printf ("True\n") ;
  else printf ("False\n") ;
  return 0 ;
}
