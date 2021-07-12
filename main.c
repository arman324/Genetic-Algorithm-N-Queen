#include <stdio.h>
#include "type.h"
#include <unistd.h>

void initialize();
void generation();
void nextGen();
void initReport();


int main(int argc, char **argv) {
  int gen = 0;
  initialize();
  while(gen < 500){ //100?
    generation();
    initReport();
    nextGen();
    if (flag > 0) break;
    gen++;
}
  return 0;
}
