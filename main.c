#include <stdio.h>
#include "type.h"

void initialize();
void generation();

int main(int argc, char **argv) {
  int i = 0;
  initialize();
  while(i < 1){ //100?
    generation();


    i++;
}
  return 0;
}
