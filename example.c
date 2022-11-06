// this program shows off all map.h functions
#include <stdio.h>
#define MAP_FULL_INT // real ints instead of uint8
#include "map.h"

int main(void) {
  map_graph _map = map_new(5); // 5,5 large graph with ints in it
  map_graph *map = &_map;
  map_set(1,4,1,map); // place 1 at 1,4
  struct _map_vec2 a = map_find(1,map); // get the coordinates of first occurence of 1
  if (a.x<0) {
    printf("No occurence of 1");
  }
  else {
    printf("%i\n",map_get(a.x,a.y,map));// use the coordinates to print 1
  }
  return 0;
}
