#include <stdio.h>
#include <stdlib.h>

void division (int dividende, int diviseur, int nb_decim) {
  int reste, quotient ;

  /* Ne pas oublier le cas de la division par 0. */
  if (diviseur == 0) {
    printf ("Division by 0.\n") ;
    return ;
	}

  if ((dividende > 0) != (diviseur > 0)) {
    printf ("-") ;
    if (dividende < 0) dividende = - dividende ;
    else diviseur = - diviseur ;
  }

  /* Calcul de la partie enti�re. */
  quotient = dividende / diviseur ;
  reste = dividende % diviseur ;
  printf ("%d", quotient) ;
  /* Point uniquement si partie d�cimale non vide. */
  if (reste != 0) printf (".") ;

  /* It�ration pour la partie d�cimale. */
  while ((nb_decim > 0) && (reste != 0)) {
    dividende = reste * 10 ;  /* On "abaisse" toujours un 0. */
    quotient = dividende / diviseur ;
    reste = dividende % diviseur ;
    printf ("%d", quotient) ;
    nb_decim-- ;
  }

  if (reste == 0) printf ("\nR�sultat exact\n.") ;
  else printf ("\nR�sultat approch� (reste %d)\n.", reste) ;
}


int main (int argc, char *argv[])
{
  if (argc != 4) {
    printf ("Erreur. Mauvais nombre d'arguments.\n") ;
    return 1 ;
  }

  division (atoi (argv[1]), atoi (argv[2]), atoi (argv[3])) ;
  return 0 ;
}
