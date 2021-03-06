
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int popSize;
int lchrom;
int population[1000][200] = {0};
int children[1000][200] = {0};
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
int ci1[200] = {0};
int ci2[200] = {0};
int MaxGen = 0;
int gen = 0;
int solution[200] = {0};
double pMut;
double pMutTemp;
double pCross;
int cnt = 0;
int modes = 0;

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

    printf("Enter chromosome length - lChrom-> ");
    scanf("%d", &lchrom);
    printf("chromosome length is : %d\n", lchrom);

    printf("Enter MaxGen - MaxGen -> ");
    scanf("%d", &MaxGen);
    printf("MaxGen is : %d\n", MaxGen);

    printf("Enter pMut - pMut -> ");
    scanf("%lf", &pMut);
    //pMut = 0.001;
    pMutTemp = pMut;

    printf("pMut is : %lf\n", pMut);

    printf("Enter pCross - pCross -> ");
    scanf("%lf", &pCross);
    //pCross = 0.8;
    printf("pCross is : %lf\n", pCross);

}

void initPop(){ //generate population

  int j;
  int i;

  srand(5);

	int seed[1000][200];

  for(i=0; i<popSize; i++) {
     for(j=0; j<lchrom; j++) {
       seed[i][j] = rand();
     }
  }
//
  for(i=0; i<popSize; i++) {
     for(j=0; j<lchrom; j++) {
        population[i][j] = advance_random(lchrom,seed[i][j]); //generate random population
     }
  }
//
  for(i=0; i<popSize; i++) {
    fitness[i] = eval(population[i], lchrom); //calculate fitness
  }

}

void initReport(){

  printf("\n\nPopulation Size(popsize)  %d\n", popSize);
  printf("Chromosome length (lchrom)  %d\n", lchrom);
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
