# map
a header to help you with graphs

## docs
### MAP_FULL_INT
``#define MAP_FULL_INT``
data in the graph is stored in char's (or 8 bit ints) defining map_full_int makes it a normal integer

### _map_vec2
``struct _map_vec2``

A struct with 2 ints (``_map_vec2.x`` and ``_map_vec2.y``)

returned by map_find as a workaround from pointers

> twod_to_oned()

``int twod_to_oned(unsigned int x,unsigned int y)``

returns a oned position of x,y

> map_new()

``map_graph map_new(unsigned int size)``

makes a new initialized map_graph struct thats size large

> map_set()

``void map_set(unsigned int x,unsigned int y,int set_to,map_graph *map)``

set x_y in map to the set_to int

> map_get()

``int map_get(unsigned int x,unsigned int y,map_graph *map)``

get x_y in map and return

> map_find()

``struct _map_vec2 map_find(int what_to_find,map_graph *map)``

return a ``_map_vec2`` with the x and y coordinate of the first occurence of what_to_find

# why tf
1. fun
2. fast
3. simple
4. despite being dynamic only c99 compiler required
