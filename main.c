#include <stdio.h>
#include "type.h"

void initialize();
void generation();
void initReport();

int main(int argc, char **argv) {
  int i = 0;
  initialize();
  while(i < 1){ //100?
    generation();
    initReport();

    i++;
}
  return 0;
}
