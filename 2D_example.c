#include "map.h"
#include <stdio.h>
int main() {
  // as an example for 2D, we will be making a square inside a 2D graph then printing it
  map2 map = map2_new(8); // to make the square more visible we will make everything in the table 8
  int radius = 10; // how big we want our square to be
  int start_x = 5; // where top left corner of square is
  int start_y = 5; // where top left corner of square is

  /* how will we draw the square?
  I would like to start drawing the square by moving to the right radius times
  then moving down on the y radius times making the first half of the square
  then do the same but thing but inverted
  */
  int a; // for loop
  // move to the right on x axis
  for (a=1;a < radius;a++) {
    map2_set(&map,start_x+a,start_y,1);
  }
  // move down on the y axis
  for (a=1;a < radius;a++) {
    map2_set(&map,start_x+radius,start_y+a,1);
  }
  // now do the same thing but taking into account what we allready have
  
  // move up on the y axis
  for (a=1;a < radius;a++) {
    map2_set(&map,start_x+radius-a,start_y+radius,1);
  }
  // move to the left on the x axis
  for (a=1;a < radius;a++) {
    map2_set(&map,start_x,start_y+radius-a,1);
  }
  // and here we render the square, the graph is actually 50*50 but we only used a bit of it
  // you need a terminal thats more than 20*30 characters in size to see this correctly
  int b;
  for (a=1;a < 20;a++) {
    printf("\n");
    for (b=1;b < 30;b++) {
      printf("%i",map2_get(map,a,b));
    }
  }
}
