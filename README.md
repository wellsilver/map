see example.c to learn how it (in 2D) works

![image](https://user-images.githubusercontent.com/67511181/193435358-765ebae9-52b0-4d0a-866f-6f5585846fe2.png)

the square above was made with this
```c
  map2 map;
  int a;int b;
  for (a=1;a < 20;a++) {
    printf("\n");
    for (b=1;b < 30;b++) {
      printf("%i",map2_get(map,a,b));
    }
  }```
# map2

a 2D graph 50*50 large

## methods

### map2 map2_new(int default_)
make a new 50*50 2D graph with this default integer

### int map2_get(map2 map,int x,int y)
get the integer at x_y convenience function
```c
return map.x[x].y[y];
```
### void map2_set(map2 *map,int x,int y,int data) {
change x_y to int data convenience function
```c
map->x[x].y[y] = data;
```

# map3

the same functions as map2, except really inefficient and confusing (just dont use it)

# why tf
1. fun to do
2. standardization
3. portable
4. no-std
