void *malloc(unsigned long int size); // custom dec so no std
// 1 dimension
struct data {
  int *y;
};
// dynamicly sized 2D graph
struct map {
  int size;
  struct data *x;
};
typedef struct map map;
// make a new map with size x_y
map map_new(int size)  {
  map i;
  i.size=size;
  i.x = (struct data *) malloc(sizeof(struct data)*size);
  int a;
  for (a=1;a < size;a++) {
    i.x[a].y = (int *) malloc(sizeof(int)*size);
  }
  return i;
}
// get key at x_y map
int map_get(map *map,int x,int y) {
  return map->x[x].y[y];
}
// set key at x_y map to data
void map_set(map *map,int x,int y,int data) {
  map->x[x].y[y] = data;
}
/* find the x_y coordinates of first occurence of data and return its coordinates in array
*/
int *map_find(map *map,int data) {
  int a;int b;
  for (a=1;a < map->size;a++) {
    for (b=1;b < map->size;b++) {
      if (map->x[a].y[b]==data) {
        int *array = (int *) malloc(sizeof(int)*2);
        array[0] = a;
        array[1] = b;
        return array;
      }
    }
  }
}
