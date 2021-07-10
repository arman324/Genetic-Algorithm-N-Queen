#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int popSize;
int lchrom;
void initData();
void initPop();

void initialize(){

  initData();
  initPop();

}

void initData(){

  while(1){
    printf("Enter population size (use 50 or 100) - popSize-> ");
    scanf("%d", &popSize);
    if (popSize == 50 || popSize == 100){
      printf("population size is : %d\n",popSize);
      break;
    }
    else{
      printf("\nNote population size must be 50 or 100\n");
      continue;
    }
  }
  while(1){
    printf("Enter chromosome length (8 queen or 25 queen or 50 queen) - lChrom-> ");
    scanf("%d", &lchrom);
    if (lchrom == 8 || lchrom == 25  || lchrom == 50){
      printf("chromosome length is : %d\n",lchrom);
      break;
    }
    else{
      printf("\nNote chromosome length must be 8 or 25 or 50\n");
      continue;
    }
  }
}

void initPop(){ //init population
  printf("We are in initPop\n");
  printf("%d,%d\n",popSize,lchrom);
}
