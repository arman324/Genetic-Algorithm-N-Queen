#include <stdio.h>
#include "type.h"
#include <unistd.h>

void initialize();
void generation();
void nextGen();
void initReport();
void report(int flag);


int main(int argc, char **argv) {
  gen = 0;
  initialize();

  while(gen < MaxGen){ //100?
    generation();
    initReport();
    nextGen();
    if (maxFitness == 1.000000)
    {
      report(1);
      break;
      return 0;
    }
    gen++;
  }

  report(0);
  return 0;

}
