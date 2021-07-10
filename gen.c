#include <stdio.h>
#include "type.h"

int roulette(int sumFitness, int popSize);

void generation(){

  int p1, p2;

  for (int i=0; i < popSize; i++){
    normal_fitness = (fitness[i]/sumFitness);
    comulative += normal_fitness;
    comulative_fitness[i] = comulative;
  }

  p1 = roulette(sumFitness, popSize);
  p2 = roulette(sumFitness, popSize);

  for (int i = 0; i< lchrom; i++){
    printf("%d ", population[p1][i]);
  }
  printf("\n");

}
