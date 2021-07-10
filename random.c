#include <stdio.h>
#include <stdlib.h>

int rnd(int high, int seed){

  srand(seed);
  return rand()%high + 1;
}
