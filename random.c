#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int advance_random(int high, int seed){

  srand(seed);
  return rand()%high + 1;
}

float f_random(){
  float rnd = ((float)rand()/RAND_MAX);
  return rnd;
}

int rnd(int low, int high)
{ /* pick a random int between low and high */
  int i;

  if(low >= high) {
    i = low;
  } else {
    i = rand()%(high-low) + 1;
  }
  return i;
}
