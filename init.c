#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initData();

void initialize(){
  printf("Init\n");

  initData();

}

void initData(){
  int popSize;
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
  printf("here\n");

}
