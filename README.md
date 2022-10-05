see example.c to learn how it works

![image](https://user-images.githubusercontent.com/67511181/194119664-08f08752-6a6a-40ac-9280-30a61242ec70.png)

<small>the image is a 20*30 table</small>
# map2

a 2D graph thats size can be changed

## methods

### map map_new(int size)
make a new map with size x_y for example if size was 50 it would be 50*50

### int map_get(map2 map,int x,int y)
get the key at x_y in the map
```c
return map->x[x].y[y];
```
### void map_set(map2 *map,int x,int y,int data) {
set key at x_y map to data
```c
map->x[x].y[y] = data;
```
### int *map_find(map *map,int data)
find the x_y coordinates of first occurence of data and return its coordinates in integer array

## 3D
because of how dumb 3D is itll only be added if someone else adds it (via pr)

# why tf
1. fun to do
2. standardization
3. portable
4. no-std
