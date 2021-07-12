#include <stdio.h>
#include "type.h"


void statistics(int popSize){ /* calculate population stats */
 double temp = 0;

  for(int i=0; i<popSize; i++) {
    sumFitness += fitness[i];
  }

  maxFitness = fitness[0];
  minFitness = fitness[0];
  for(int i=1; i<popSize; i++) {
    temp = fitness[i];

    if (maxFitness < temp) {
      maxFitness = temp;
    }
    if (minFitness > temp) {
      minFitness = temp;
    }
  }

  avgFitness = sumFitness / (double) popSize;
}
