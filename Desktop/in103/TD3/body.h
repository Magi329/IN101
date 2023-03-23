#ifndef __BODY_H__
#define __BODY_H__


struct body_t {
  int color ;      
  int radius ;     
  double mass ;    
  double x, y ;    
  double vx, vy ;  
  double ax, ay ;  
} ;



struct body_list_t {
  struct body_t *body ;
  struct body_list_t *next ;
} ;

/** Create and register in a linked list a new body.  */
struct body_list_t* new_body (struct body_list_t* l, int color, int radius,
                              double mass,
                              double x, double y, double vx, double vy) ;

/** Use velocity and acceleration to renew the position */
void move_body (struct body_t *b) ;
#endif
