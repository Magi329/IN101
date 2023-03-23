#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "station.h"
#include "load_map.h"
#include "queue.h"
#include "search.h"


bool shortest_path (struct station_t *src, struct station_t *dest)
{
  struct queue_t *queue = queue_alloc (512) ;
  bool found = false ;

  if (queue == NULL) {
    printf ("Erreur: impossible d'allouer la file.\n") ;
    return (false) ;
  }

  /* Racine = station de d�part. La marquer. */
  src->seen = true ;
  /* La mettre dans la file. */
  enqueue (queue, src) ;
  /* Tant que la file n'est pas vide... */
  while ((! is_empty (queue)) && (! found)) {
    struct station_t *st = take (queue) ;
    printf ("Station courante: %s\n", st->name) ;
    /* V�rifier si on est arriv� � la destination. */
    if (st == dest) found = true ;
    else {
      /* Sinon on continue le parcours. */
      struct stations_list_t *neigh = st->neighbours ;
      while (neigh != NULL) {
        /* V�rifier si le voisin n'est pas d�j� marqu�. */
        if (! neigh->station->seen) {
          /* Pas marqu�, donc le marquer et le mettre dans la file. */
          neigh->station->seen = true ;
          /* On se souvient que lorsque l'on traitera ce voisin, on y sera
             arriv� par l'interm�diaire du noeud actuel. */
          neigh->station->prev_in_path = st ;
          enqueue (queue, neigh->station) ;
        }
        /* Voisin suivant. */
        neigh = neigh->next ;
      }
    }
  }

  queue_free (queue) ;
  return (found) ;
}



/** Imprime le chemin trouve, en ordre inverse (donc, destination vers source).
    Si aucun chemin n'a �t� trouv�, le r�sultat sera impr�dictible. */
void print_shortest_path_reversed (struct station_t *last)
{
  struct station_t *st = last ;
  while (st != NULL) {
    printf ("%s", st->name) ;
    st = st->prev_in_path ;
    /* Pour n'afficher une fl�che que s'il y a bien d'autres stations apr�s
       la courante. */
    if (st != NULL) printf (" <- ") ;
  }

  printf ("\n") ;
}
