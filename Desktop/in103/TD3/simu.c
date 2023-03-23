#include <stdlib.h>

#include "body.h"
#include "simu.h"


/* define the forces */
void f1 (double x, double y, double vx, double vy, double *fx, double *fy)
{
  *fx = 2*x ;
  *fy = 3*y ;
}//lié aux champs/position

void f2 (double x, double y, double vx, double vy, double *fx, double *fy)
{
  *fx = -vx ;
  *fy = -vy ;
} //frottement


force_t forces_array[] = { f1,f2, NULL } ;




void apply_forces_on_body (struct body_t *b, force_t *forces)
{
  unsigned int i = 0 ;

  
  while (forces[i] != NULL) {
    double fx, fy ;

    /* Apply force */
    (forces[i]) (b->x, b->y, b->vx, b->vy, &fx, &fy) ;
    /* Update the body's acceleration  */
    b->ax = b->ax + fx / b->mass ;
    b->ay= b->ay + fy / b->mass ;
    // next
    i++ ;
  }
}



/* Apply all the forces on all the bodies. Add the gravity(ay) in the forst place, then apply other forces  */
void simulate_bodies (struct body_list_t *bl, force_t *forces)
{
  while (bl != NULL) {
    struct body_t *b = bl->body ;
    b->ax = 0.0 ;
    b->ay = -9.81 ;
    
    apply_forces_on_body (b, forces) ;
    
    move_body (b) ;

    bl = bl->next ;
  }
}

