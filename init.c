#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int popSize;
int lchrom;
int population[50][8] = {0};
double fitness[50] = {0};
void initData();
void initPop();
int advance_random(int lchrom, int seed);
double eval(int chromosome[], int lchrom);
void initReport();

void initialize(){

  initData();
  initPop();
  initReport();

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
    fitness[i] = eval(population[i], lchrom); //calculate fitness
  }

}

void initReport(){

  printf("\n\nPopulation Size(popsize)  %d\n", popSize);
  printf("Chromosome length (lchrom)  %d\n", lchrom);
  //printf("Maximum num of generations(maxgen)  %d\n", p->maxGen);
  //printf("Crossover Probability (pcross)  %lf\n", p->pCross);
  //printf("Mutation Probability (pmut)  %lf\n", p->pMut);
  //printf("\n\t\tFirst Generation Stats  \n\n");
  //printf("Maximum Fitness  %lf\n", p->max);
  //printf("Average Fitness  %lf\n", p->avg);
  //printf("Minimum Fitness  %lf\n", p->min);

  for(int i=0; i<popSize; i++) {
     printf("%d: ", i+1);
     for(int j=0; j<lchrom; j++) {
        printf("%d ", population[i][j]);
        if(j == (lchrom-1)){
           printf(" fitness => %f\n", fitness[i]);
        }
     }
  }

}
