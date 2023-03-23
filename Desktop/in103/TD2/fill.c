#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "paint.h"



void fill (int width, int height, int nb_init,unsigned char* pixels)
{
  int i;
  bool *processed;
  struct queue_t *q;
  struct point_info_t *init_points;

  /* Allocation de la file. Taille max: width * height. */
  q = queue_alloc (width * height);
  if (q == NULL) {
    printf ("No mem for queue.\n");
    return ;
  }

  /* Allocation du tableau pour se souvenir des points initiaux et redessiner
     par dessus en noir � la fin. */
  init_points = malloc (nb_init * sizeof (struct point_info_t));
  if (init_points == NULL) {
    printf ("Nom mem for initial points.\n");
    queue_free (q);
    return ;
  }

  /* Allocation du tableau disant si un point a d�j� �t� mis en file. */
  processed = malloc (width * height * sizeof (bool));
  if (processed == NULL) {
    printf ("No mem for processed array.\n");
    free (init_points);
    queue_free (q);
    return ;
  }
  /* Au d�but, aucun point n'a d�j� �t� trait�. */
  for (i = 0; i < width * height; i++) processed[i] = false;




/*remplir ici avec l'algo ! (l� �a compile mais SegFault)*/
/* initialisation */
    for (i = 0; i < nb_init; i++) {
        struct point_info_t pi ;

        pi.x = rand () % width ;
        pi.y = rand () % height ;
        pi.r = rand () % 256 ;
        pi.g = rand () % 256 ;
        pi.b = rand () % 256 ;
        enqueue (q, pi) ;

        processed[(pi.y * width) + pi.x] = true ;

        init_points[i].x = pi.x ;
        init_points[i].y = pi.y ;
        init_points[i].r = 0 ;
        init_points[i].g = 0  ;
        init_points[i].b = 0  ;
    }


  int* r,g,b;
  struct point_info_t pi;
  while( !is_empty(q)){
      struct point_info_t res = take(q);
      if(res.y>0 && processed[res.x+(res.y-1)*width]==false) {
          color_pixel(res.x, res.y - 1, res.r, res.g, res.b, width,height, pixels);
          pi.x = res.x;
          pi.y = res.y - 1;
          pi.r = res.r;
          pi.g = res.g;
          pi.b = res.b;
          enqueue(q,pi);
          processed[res.x+(res.y-1)*width]=true;
          }
    if(res.x>0 && processed[(res.x-1)+res.y*width]==false) {
        color_pixel(res.x-1, res.y , res.r, res.g, res.b, width,height, pixels);
        pi.x = res.x-1;
        pi.y = res.y;
        pi.r = res.r;
        pi.g = res.g;
        pi.b = res.b;
        enqueue(q,pi);
        processed[(res.x-1)+res.y*width]=true;
    }
    if(res.y<height && processed[res.x+(res.y+1)*width]==false) {
          color_pixel(res.x, res.y + 1, res.r, res.g, res.b,width,height, pixels);
          pi.x = res.x;
          pi.y = res.y + 1;
            pi.r = res.r;
            pi.g = res.g;
            pi.b = res.b;
          enqueue(q,pi);
          processed[res.x+(res.y+1)*width]=true;
      }
      if(res.x < width && processed[(res.x+1) +res.y*width]==false) {
          color_pixel(res.x+1, res.y , res.r, res.g, res.b, width,height, pixels);
          pi.x = res.x+1;
          pi.y = res.y;
          pi.r = res.r;
          pi.g = res.g;
          pi.b = res.b;
          enqueue(q,pi);
          processed[(res.x+1)+res.y*width]=true;
      }
  }
  free (init_points);
  queue_free (q);
  free (processed);
}

