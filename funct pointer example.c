#include <stdio.h>
#define MAP_FUNC_PNTRS
#include "map.h"

int main() {
  map2_graph a = map2_new(5,5,0);
  printf("%i\n",a.get(1,1,&a));
  a.set(1,1,1,&a);
  struct map2_find_ret b = a.find(1,&a);
  printf("%i\n",a.get(b.x,b.y,&a));
}
