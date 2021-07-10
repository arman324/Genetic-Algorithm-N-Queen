#include <stdio.h>
#include "type.h"

int roulette(int sumFitness, int popSize);

void generation(){

  int p1, p2;
  int om1[50] = {0};
  int om2[50] = {0};

  for (int i=0; i < popSize; i++){
    normal_fitness = (fitness[i]/sumFitness);
    comulative += normal_fitness;
    comulative_fitness[i] = comulative;
  }

  for(int i = 0; i < popSize; i += 2){

    p1 = roulette(sumFitness, popSize);
    p2 = roulette(sumFitness, popSize);

    for (int i = 0; i< lchrom; i++){
      om1[i] = population[p1][i];
      om2[i] = population[p2][i];
    }

    for (int i = 0; i< lchrom; i++){
      printf("%d ", om1[i]);
    }

    printf("\n");

    for (int i = 0; i< lchrom; i++){
      printf("%d ", om2[i]);
    }

    printf("\n");
    //crossover
  }

}
