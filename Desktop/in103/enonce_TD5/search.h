#ifndef __SEARCH_H__
#define __SEARCH_H__
#include <stdbool.h>

bool shortest_path (struct station_t *src, struct station_t *dest) ;
void print_shortest_path_reversed (struct station_t *last) ;

#endif
