#include <stdio.h>
#include "type.h"

void rawStat(int flag);


void report(int flag)
{ /* report generations stats */

  rawStat(flag);


}

void rawStat(int flag)
{

  printf("\n\nPopulation Size(popsize)  -->  %d\n", popSize);
  printf("Chromosome length (lchrom)  -->  %d\n", lchrom);
  printf("Maximum num of generations (MaxGen)  -->  %d\n", gen);
  //printf("Crossover Probability (pcross)  %lf\n", p->pCross);
  //printf("Mutation Probability (pmut)  %lf\n", p->pMut);
  printf("Maximum Fitness  -->  %f\n", maxFitness);
  printf("Average Fitness  -->  %lf\n", avgFitness);
  printf("Minimum Fitness  -->  %f\n", minFitness);
  if (flag == 1){
      printf("Solution  -->  ");
      for (int i=0; i<lchrom; i++){
        printf("%d ", solution[i]);
      }
      printf("\n");
  }
  printf("Number of Mutex  -->  %d\n", cnt);
}
