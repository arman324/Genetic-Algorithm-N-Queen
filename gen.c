#include <stdio.h>
#include "type.h"

int roulette(int sumFitness, int popSize);
void crossover(int om1[], int om2[]);
void twoPointCrossover(int om1[], int om2[]);
double eval(int chromosome[], int lchrom);
void statistics(int popSize);
float f_random();
int tournament(int popSize);


void generation(){

  int p1, p2;
  int k = 0;
  int om1[100] = {0};
  int om2[100] = {0};
  float rndm;

  for(int i = 0; i < popSize; i += 2){

    /*
    p1 = roulette(sumFitness, popSize);
    p2 = roulette(sumFitness, popSize);
*/
    p1 = tournament(popSize);
    p2 = tournament(popSize);

    for (int i = 0; i< lchrom; i++){
      om1[i] = population[p1][i];
      om2[i] = population[p2][i];
    }

    rndm = f_random();
    printf("RNDM -> %f\n", rndm);


    if (rndm <= pCross) {//pCross
      //crossover(om1,om2); //one point crossover
      twoPointCrossover(om1,om2); //two points crossover
    }
    else {
      for (int i = 0; i < lchrom; i++){
        ci1[i] = om1[i];
        ci2[i] = om2[i];
      }
    }

    for (int i = 0; i < lchrom; i++){
      children[k][i] = ci1[i];
      children[k+1][i] = ci2[i];
    }

    for (int i = 0; i < lchrom; i++){
        printf("%d ", om1[i]);
    }
    printf("\n");

    for (int i = 0; i < lchrom; i++){
        printf("%d ", om2[i]);
    }
    printf("\nnew children =>\n");

    for (int i = 0; i < lchrom; i++){
        printf("%d ", ci1[i]);
    }
    printf("\n");

    for (int i = 0; i < lchrom; i++){
        printf("%d ", ci2[i]);
    }
    printf("\n");

    k += 2;
  }
  for(int i=0; i<popSize; i++) {
    fitness_children[i] = eval(children[i], lchrom); //calculate fitness
  }

/*
  printf("\n\children =>\n\n");
  for(int i=0; i<popSize; i++) {
     printf("%d: ", i+1);
     for(int j=0; j<lchrom; j++) {
        printf("%d ", children[i][j]);
        if(j == (lchrom-1)){
           printf(" fitness => %f\n", fitness_children[i]);
        }
     }
  }*/

}

void nextGen(){
    //Turning children into parents
    for(int i=0; i<popSize; i++) {
       for(int j=0; j<lchrom; j++) {
          population[i][j] = children[i][j];
       }
    }

    //Turning children fitness into parents fitness
    for(int i=0; i<popSize; i++) {
      fitness[i] = fitness_children[i];
    }
    printf("\n\nnew parents =>\n\n");
    for(int i=0; i<popSize; i++) {
       printf("%d: ", i+1);
       for(int j=0; j<lchrom; j++) {
          printf("%d ", population[i][j]);
          if(j == (lchrom-1)){
             printf(" fitness => %f\n", fitness[i]);
             if (fitness[i] == 1.000000)
             {

               for (int k=0; k<lchrom; k++){
                 solution[k] = population[i][k];
               }
             }
          }
       }
    }


    comulative = 0;
    normal_fitness = 0;
    sumFitness = 0;

    statistics(popSize);

    for (int i=0; i < popSize; i++){
      normal_fitness = (fitness[i]/sumFitness);
      comulative += normal_fitness;
      comulative_fitness[i] = comulative;
    }

}
