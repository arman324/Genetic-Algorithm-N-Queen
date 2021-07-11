#include <stdio.h>
#include "type.h"
#include <time.h>
#include <stdlib.h>

float f_random();

int roulette(int sumFitness, int popSize)
{
  float rnd;
  int p;


  // select parents randomly with respect to fitness
  rnd = f_random();
  printf("%f\n", rnd);

  for (int i=0; i<popSize; i++){
    if (rnd > comulative_fitness[i] && rnd <= comulative_fitness[i+1]){
      p = i+1;
      i = popSize;
    }
    else if (rnd <= comulative_fitness[0]){
      p = 0;
      i = popSize;
    }
    else {
      continue;
    }
  }
  printf("COMULATIIIIIIIVEREEEE FIIIINESSSSS%d\n",p );

  return p;

}
