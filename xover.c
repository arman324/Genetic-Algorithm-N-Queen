#include <stdio.h>
#include "type.h"

int rnd(int low, int high);
float f_random();
int muteX(int pa);


void crossover(int om1[], int om2[]){

  int xp, i;
  //xp = xover point

  xp = rnd(0, lchrom-1);
  printf("xp = %d\n", xp);

  for(i = 0; i < xp; i++){
    ci1[i] = muteX(om1[i]);
    ci2[i] = muteX(om2[i]);
  }
  for(i = xp; i < lchrom; i++){
    ci1[i] = muteX(om2[i]);
    ci2[i] = muteX(om1[i]);
  }

}

int muteX(int pa){
  float rndm;
  int random_number;

  rndm = f_random();

  /*if (maxFitness > 0.95) {
    pMut = 0.01;
  }*/
  if (rndm <= pMut) {//pMut
    random_number = rnd(0, lchrom);
    cnt++;
    return random_number;
  }
  else {
    return pa;
  }
}
