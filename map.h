//
// _align is a single dimension, used by map.h
struct _align {
  int y[50];
};
// a 2D graph, dont use "struct map2" just do "map2"
struct map2 {
  struct _align x[50];
};
// a 2D graph, used by map.h
typedef struct map2 map2;
// conveniently make a map2 with default integer
map2 map2_new(int default_) {
  map2 i;
  int a;int b;
  for (a=1;a < 50;a++) {
    for (b=1;b < 50;b++) {
      i.x[a].y[b] = default_;
    }
  }
  return i;
}
// conveniently (and while looking cleaner) get the key at x_y
int map2_get(map2 map,int x,int y) {
  return map.x[x].y[y];
}
// conveniently (and while looking cleaner) set the key at x_y to i
void map2_set(map2 *map,int x,int y,int data) {
  map->x[x].y[y] = data;
}

/// map3 (3d graph)
/* we allready have 2 dimensions, we can just put the 2 dimension graph in an array
and follow by z

x,y,z is normal but y,x,z is alot more readable?
*/
// xyz
struct _map3_z {int z[50];};
struct _map3_x {struct _map3_z x[50];};
// 3D graph like this (y,x,z)
struct map3 {
  struct _map3_x y[50];
};
// 3D graph like this (y,x,z) imagine y as a bunch of 2D graphs
typedef struct map3 map3;
// funcs
// conveniently make a map3 with default integer
map3 map3_new(int default_) {
  map3 i;
  int a;int b;int c;
  for (a=1;a < 50;a++) {
    for (b=1;b < 50;b++) {
      for (c=1;c < 50;c++) {
        i.y[a].x[b].z[c] = default_;
      }
    }
  }
  return i;
}
// conveniently (and while looking cleaner) get the key at y_x_z
int map3_get(map3 map,int x,int y,int z) {
  return map.y[x].x[y].z[z];
}
// conveniently (and while looking cleaner) set the key at y_x_z
void map3_set(map3 *map,int x,int y,int z,int data) {
  map.y[x].x[y].z[z] = data;
}
// conveniently get a map2 from map3 for the graph on y coordinate
map2 map3_into_map2(map3 map,int y) {
  map2 i;
  int a;int b;
  for (a=1;a < 50;a++) {
    for (b=1;b < 50;b++) {
      i.x[a].y[b]=map.y[y].x[a].z[b];
    }
  }
  return i;
}
