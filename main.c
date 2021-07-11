#include <stdio.h>
#include "type.h"

void initialize();
void generation();
void nextGen();
void initReport();
void statistics(int popSize, double fitness[]);


int main(int argc, char **argv) {
  int gen = 0;
  initialize();
  while(gen < 1){ //100?
    generation();
    initReport();
    nextGen();

    //statistics(popSize, fitness);

    gen++;
}
  return 0;
}
