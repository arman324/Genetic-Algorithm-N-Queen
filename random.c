#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int high, int seed){

  srand(seed);
  return rand()%high + 1;
}

float f_random(){
  float rnd = ((float)rand()/RAND_MAX);
  return rnd;
}
