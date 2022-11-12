#include <stdio.h>
#include "map.h"

int main() {
  map2_graph a = map2_new(5,5,0);
  printf("%i\n",map2_get(1,1,&a));
  map2_set(1,1,1,&a);
  struct map2_find_ret b = map2_find(1,&a);
  printf("%i\n",map2_get(b.x,b.y,&a));
}
