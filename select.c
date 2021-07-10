#include <stdio.h>
#include "type.h"



void roulette(int sumFitness, int popSize)
{
  for (int i=0; i < popSize; i++){
    normal_fitness = (fitness[i]/sumFitness)*100;
    comulative += normal_fitness;
    comulative_fitness[i] = comulative;
  }
  // select parents randomly with respect to fitness



}
