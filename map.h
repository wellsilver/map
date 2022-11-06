// dynamicly sized 2D graph
typedef struct _map_vec2 {
  int x;
  int y;
} _map_vec2;
typedef enum map_style {MAP_STYLE_INT,MAP_STYLE_CHR} map_style;
// map is just 2D array
typedef struct map_graph {
  map_style style;
  int size;
#ifdef MAP_FULL_INT
  int *i;
#endif
#ifndef MAP_FULL_INT
  char *i;
#endif
} map_graph;

// 
int twod_to_oned(unsigned int x,unsigned int y) {
  if (x>1 && y>1) { // if they are both greater than 1
    return x*y;
  }
  else { // if one is not greater than 1
    return x+y;
  }
}
// make a new 2D graph with datatype map_style \n as large as x,y \n if init is > 0 all keys are set to 0
map_graph map_new(unsigned int size,map_style style) {
  map_graph map;
  map.size=size;
  map.style=style;
#ifdef MAP_FULL_INT
  int i[size];
#endif
#ifndef MAP_FULL_INT
  char i[size];
#endif
  //graph.i = (int *) malloc(sizeof(int)*size);
  map.i=i;
  int loop;
  int loop2;
  for (loop=0;loop<map.size;loop++) {
    for (loop2=0;loop2<map.size;loop2++) {
      map.i[twod_to_oned(loop,loop2)]=0;
    }
  }
  return map;
}
// set x_y in map to set_to
void map_set(unsigned int x,unsigned int y,int set_to,map_graph *map) {
  int pos=twod_to_oned(x,y);
  map->i[pos] = set_to;
}
// return x_y in map
int map_get(unsigned int x,unsigned int y,map_graph *map) {
  int pos=twod_to_oned(x,y);
  return map->i[pos];
}
// find first instance of int (or char) and return as _map_vec2 of coordinates
struct _map_vec2 map_find(int what_to_find,map_graph *map) {
  int loop;
  int loop2;
  struct _map_vec2 ret;
  ret.x=-1;
  ret.y=-1;
  for (loop=0;loop<map->size;loop++) {
    for (loop2=0;loop2<map->size;loop2++) {
      if (map->i[twod_to_oned(loop,loop2)]==what_to_find) {
        ret.y = loop;
        ret.x = loop2;
        return ret;
      }
    } 
  }
  // if no occurence
  return ret;
}
