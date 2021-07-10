#include <stdio.h>
#include <stdlib.h>

int advance_random(int lchrom, int seed){

  srand(seed);
  return rand()%lchrom + 1;
}
