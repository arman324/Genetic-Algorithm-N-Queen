#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int popSize;
int lchrom;
void initData();
void initPop();
int advance_random(int lchrom, int seed);

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

void initPop(){ //generate population
  int population[50][8] = {0};

  printf("Two Dimensional array elements:\n");
  int j;
  int i;

  srand(time(NULL));

	int seed[50][8];

  for(i=0; i<popSize; i++) {
     for(j=0; j<lchrom; j++) {
       seed[i][j] = rand();
     }
  }

  for(i=0; i<popSize; i++) {
     for(j=0; j<lchrom; j++) {
        population[i][j] = advance_random(lchrom,seed[i][j]); //generate random population
     }
  }

  for(i=0; i<popSize; i++) {
     printf("%d: ", i+1);
     for(j=0; j<lchrom; j++) {
        printf("%d ", population[i][j]);
        if(j == (lchrom-1)){
           printf("\n");
        }
     }
  }

}
