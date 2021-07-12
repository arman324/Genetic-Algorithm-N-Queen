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
  int flag = 0;
  initialize();

  while(gen < MaxGen){
    generation(); // roulette wheel or tournament
    initReport();
    nextGen();

    if (maxFitness == 1.000000)
    {
      report(1);
      flag = 1;
      break;

    }
    gen++;
  }
  if (flag != 1) report(0);
  return 0;

}
