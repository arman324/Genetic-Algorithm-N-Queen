#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int popSize;
int lchrom;
int population[1000][50] = {0};
int children[1000][50] = {0};
double fitness[1000] = {0};
double fitness_children[1000] = {0};
double sumFitness = 0;
double maxFitness = 0;
double minFitness = 0;
double avgFitness = 0;
double normal_fitness = 0;
double comulative = 0;
double comulative_fitness[1000] = {0};
double comulative_sub[1000] = {0};
int ci1[50] = {0};
int ci2[50] = {0};


void initData();
void initPop();
int advance_random(int high, int seed);
double eval(int chromosome[], int lchrom);
void initReport();
void statistics(int popSize);

void initialize(){

  initData();

  initPop();

  statistics(popSize); //calculate sum of fitness

  for (int i=0; i < popSize; i++){
    normal_fitness = (fitness[i]/sumFitness);
    comulative += normal_fitness;
    comulative_fitness[i] = comulative;
  }
  //initReport();

}

void initData(){/* inittialize global params,

     popsize:   population size
     lchrom :   chromosome lenght
     maxgen :   maximum no. of generations.
     pcross :   crossover probability
     pmut   :   mutation probability           */

    printf("Enter population size - popSize-> ");
    scanf("%d", &popSize);
    printf("population size is : %d\n",popSize);


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

	int seed[1000][50];

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
  printf("Maximum Fitness  %f\n", maxFitness);
  printf("Average Fitness  %lf\n", avgFitness);
  printf("Minimum Fitness  %f\n", minFitness);

  for(int i=0; i<popSize; i++) {
     printf("%d: ", i+1);
     for(int j=0; j<lchrom; j++) {
        printf("%d ", population[i][j]);
        if(j == (lchrom-1)){
           printf(" fitness => %f   %f\n", fitness[i],comulative_fitness[i]);
        }
     }
  }

}
