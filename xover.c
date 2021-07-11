#include <stdio.h>
#include "type.h"

int rnd(int low, int high);


void crossover(int om1[], int om2[]){

  int xp, i;
  //xp = xover point


  xp = rnd(0, lchrom-1);
  printf("xp = %d\n", xp);

  for(i = 0; i < xp; i++){
    ci1[i] = om1[i];
    ci2[i] = om2[i];
  }
  for(i = xp; i < lchrom; i++){
    ci1[i] = om2[i];
    ci2[i] = om1[i];
  }

}

int muteX(int pa){

  //return (flip(p->pMut) ? 1 - pa  : pa);
  return pa;
}
