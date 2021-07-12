#include <stdio.h>
#include "type.h"
#include <time.h>
#include <stdlib.h>

float f_random();
int tournament(int popSize);
int TCrnd(int low, int high);



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

  return p;

}

int tournament(int popSize)
{
  int rnd1,rnd2;
  double f1,f2;

  // select k parents randomly from all parents
  rnd1 = TCrnd(0, popSize);
  f1 = fitness[rnd1];

  rnd2 = TCrnd(0, popSize);
  f2 = fitness[rnd2];

  if (f1 > f2){
    return rnd1;
  }else{
    return rnd2;
  }


}
