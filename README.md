see dynamic.c and static.c to see how it works

## why?
1. static and dynamic modes if you want std or not
2. fast
3. simple
4. doesnt segfault like v2 and v1

## docs
``#DEFINE MAP_STATIC``

Changes into a zero STD c99 only area

``#DEFINE MAP_SIZE``

Only for when the map is static, this changes the maps size

``map2_graph map2_new(int x,int y,int deflt)``

note: when MAP_STATIC is defined both args x and y do not exist

Create a new 2D graph thats x,y large and all keys are initialized as deflt

``int map2_get(int x,int y,map2_graph *map)``

Get the integer at x y

``void map2_set(int x,int y,int set_to,map2_graph *map)``

set the integer at x y to set_to

``struct map2_find_ret map2_find(int to_find,map2_graph *map)``

finds the first occurence of to_find in the graph and returns a struct with a x and y of its coordinates

x and y are -5 if to_find does not exist
