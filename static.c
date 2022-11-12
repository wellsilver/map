#include <stdio.h>
#define MAP_STATIC // the map is static (no STD required only c99)
#define MAP_SIZE 5 // the maps size
#include "map.h"

int main() {
  map2_graph a = map2_new(0);
  printf("%i\n",map2_get(1,1,&a));
  map2_set(1,1,1,&a);
  struct map2_find_ret b = map2_find(1,&a);
  printf("%i\n",map2_get(b.x,b.y,&a));
  
}
