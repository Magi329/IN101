#include <stdio.h>

void count (int *t, unsigned int tlen, int n) {
  int i, j ;
  int cpt = 0 ;

  for (i = 0; i < tlen; i++) {
    /* The same element can be taken twice. */
    if (t[i] - t[i] == n) cpt++ ;
    /* However, one must start at j equal to the next cell because one
       does not want to count twice the case with twice the same element
       by symmetry.
       That's the reason of the particular case above. */
    for (j = i + 1; j < tlen; j++) {
      /* Attention, a "paire" is ordered. So (a, b) <> (b, a). */
      if (t[i] - t[j] == n) cpt++ ;
      if (t[j] - t[i] == n) cpt++ ;
    }
  }
  printf ("%d\n", cpt) ;
}


int main () {
#define TLEN (4)
  int t1[TLEN] = { 1, 2, 3, 4 } ;
  int t2[TLEN] = { 0, 0, 0, 0 } ;
  int t3[TLEN] = { -1, -1, -1, -1 } ;

  count (t1, TLEN, 1) ;
  count (t1, TLEN, 0) ;
  count (t1, TLEN, -1) ;
  count (t2, TLEN, 0) ;
  count (t3, TLEN, -1) ;

  return 0 ;
}
