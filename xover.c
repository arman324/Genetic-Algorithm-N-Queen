#include <stdio.h>
#include "type.h"

int rnd(int low, int high);
float f_random();
int muteX(int pa);
int TCrnd(int low, int high);
void swapMuteX(int flag);


void crossover(int om1[], int om2[]){ //one point crossover

  int xp, i;
  //xp = xover point

  xp = rnd(0, lchrom-1);
  printf("xp = %d\n", xp);


  if (modes == 2){ //MuteX
    for(i = 0; i < xp; i++){
      ci1[i] = muteX(om1[i]);
      ci2[i] = muteX(om2[i]);
    }
    for(i = xp; i < lchrom; i++){
      ci1[i] = muteX(om2[i]);
      ci2[i] = muteX(om1[i]);
    }
}

/*
  //swapMuteX
  for(i = 0; i < xp; i++){
    ci1[i] = om1[i];
    ci2[i] = om2[i];
  }
  for(i = xp; i < lchrom; i++){
    ci1[i] = om2[i];
    ci2[i] = om1[i];
  }
  swapMuteX(1);
  swapMuteX(2);
*/
}

void twoPointCrossover(int om1[], int om2[]){
  int xp1, xp2, i;
  //xp = xover point

  xp1 = TCrnd(1, lchrom-3);
  xp2 = TCrnd(xp1+2, lchrom);

  printf("xp1 = %d\n", xp1);
  printf("xp2 = %d\n", xp2);


  if (modes == 1){ //MuteX
    for(i = 0; i < xp1; i++){
      ci1[i] = muteX(om1[i]);
      ci2[i] = muteX(om2[i]);
    }
    for(i = xp1; i < xp2; i++){
      ci1[i] = muteX(om2[i]);
      ci2[i] = muteX(om1[i]);
    }
    for(i = xp2; i < lchrom; i++){
      ci1[i] = muteX(om1[i]);
      ci2[i] = muteX(om2[i]);
    }
  }

  if (modes == 3){ //swapMuteX
    for(i = 0; i < xp1; i++){
      ci1[i] = om1[i];
      ci2[i] = om2[i];
    }
    for(i = xp1; i < xp2; i++){
      ci1[i] = om2[i];
      ci2[i] = om1[i];
    }
    for(i = xp2; i < lchrom; i++){
      ci1[i] = om1[i];
      ci2[i] = om2[i];
    }
    swapMuteX(1);
    swapMuteX(2);
  }
}

int muteX(int pa){
  float rndm;
  int random_number;

  rndm = f_random();

  if (maxFitness > 0.97) {
    pMut = 0.01;
  } else pMut = 0.001;

  if (rndm <= pMut) {//pMut
    random_number = rnd(0, lchrom);
    cnt++;
    return random_number;
  }
  else {
    return pa;
  }
}

void swapMuteX(int flag){
  float rndm;
  int temp;
  int swap1, swap2;

  swap1 = TCrnd(0, lchrom-2);
  swap2 = TCrnd(swap1+1, lchrom);

  //printf("swap1 = %d\n", swap1);
  //printf("swap2 = %d\n", swap2);

  rndm = f_random();

  if (maxFitness > 0.97) {
    pMut = 0.01;
  } else pMut = 0.001;

  if (flag == 1){
    if (rndm <= pMut) {//pMut
      temp = ci1[swap1];
      ci1[swap1] = ci1[swap2];
      ci1[swap2] = temp;
      cnt++;
    }
  }
  else if (flag == 2){
    if (rndm <= pMut) {//pMut
      temp = ci2[swap1];
      ci2[swap1] = ci2[swap2];
      ci2[swap2] = temp;
      cnt++;
    }
  }

}
