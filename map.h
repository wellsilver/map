#ifdef MAP_STATIC // static map sizes (no malloc)
typedef struct map2_graph {
  struct ABCDEFGHIJKLMNOPQRSTUVWXYZ_NOWIKNOWMYABCWONTYOULATERSINGWITHME {
    int x;
    int y;
  }size;
  int x[MAP_SIZE][MAP_SIZE];
#ifdef MAP_FUNC_PNTRS
  int (*get)(int x,int y,struct map2_graph *map);
  void (*set)(int x,int y,int set_to,struct map2_graph *map);
  struct map2_find_ret (*find)(int to_find,struct map2_graph *map);
#endif
} map2_graph;
int map2_get(int x,int y,map2_graph *map) {
  return map->x[x][y];
}
void map2_set(int x,int y,int set_to,map2_graph *map) {
  map->x[x][y] = set_to;
}
struct map2_find_ret {
  int x;
  int y;
};
struct map2_find_ret map2_find(int to_find,map2_graph *map) {
  int loop;
  int loop2;
  struct map2_find_ret e;
  for (loop=0;loop<map->size.x;loop++) {
    for (loop2=0;loop2<map->size.y;loop2++) {
      if (map->x[loop][loop2]==to_find) {
        e.x = loop;
        e.y = loop2;
        return e;
      }
    }
  }
  e.x=-5;
  e.y=-5;
  return e;
}
map2_graph map2_new(int deflt) {
  map2_graph i;
#ifdef MAP_FUNC_PNTRS
  i.get = map2_get;
  i.set = map2_set;
  i.find = map2_find;
#endif
  i.size.x = MAP_SIZE;
  i.size.y = MAP_SIZE;
  int loop;
  int loop2;
  for (loop=0;loop<MAP_SIZE;loop++) {
    for (loop2=0;loop2<MAP_SIZE;loop2++) {
      i.x[loop][loop2]=deflt;
    }
  }
  return i;
}
#else // dynamic map sizes (malloc)
#include <stdlib.h>
typedef struct map2_graph {
  struct ABCDEFGHIJKLMNOPQRSTUVWXYZ_NOWIKNOWMYABCWONTYOULATERSINGWITHME {
    int x;
    int y;
  }size;
  int **x;
#ifdef MAP_FUNC_PNTRS
  int (*get)(int x,int y,struct map2_graph *map);
  void (*set)(int x,int y,int set_to,struct map2_graph *map);
  struct map2_find_ret (*find)(int to_find,struct map2_graph *map);
#endif
} map2_graph;
// get and return x_y
int map2_get(int x,int y,map2_graph *map) {
  return map->x[x][y];
}
// set x_y to set_to
void map2_set(int x,int y,int set_to,map2_graph *map) {
  map->x[x][y] = set_to;
}
// finds first occurence of to_find and returns an array of 2 integers of its location (int i[2] = {x,y})
struct map2_find_ret {
  int x;
  int y;
};
struct map2_find_ret map2_find(int to_find,map2_graph *map) {
  int loop;
  int loop2;
  struct map2_find_ret e;
  for (loop=0;loop<map->size.x;loop++) {
    for (loop2=0;loop2<map->size.y;loop2++) {
      if (map->x[loop][loop2]==to_find) {
        e.x=loop;
        e.y=loop;
        return e;
      }
    }
  }
  e.x=-5;
  e.y=-5;
  return e;
}
// make a new graph thats x*y large and all keys are set to deflt
map2_graph map2_new(int x,int y,int deflt) {
  map2_graph i;
#ifdef MAP_FUNC_PNTRS
  i.get = map2_get;
  i.set = map2_set;
  i.find = map2_find;
#endif
  i.size.x = x;
  i.size.y = y;
  int loop;
  i.x = (int **) malloc(sizeof(int **)*x);
  for (loop=0;loop<x;loop++) {
    i.x[loop] = (int *) malloc(sizeof(int *)*y);
  }
  int loop2;
  for (loop=0;loop<x;loop++) {
    for (loop2=0;loop2<y;loop2++) {
      i.x[loop][loop2] = deflt;
    }
  }
  return i;
}
#endif
