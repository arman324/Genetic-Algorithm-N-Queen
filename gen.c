#include <stdio.h>
#include "type.h"

int roulette(int sumFitness, int popSize);
void crossover(int om1[], int om2[]);
double eval(int chromosome[], int lchrom);


void generation(){

  int p1, p2;
  int k = 0;
  int om1[50] = {0};
  int om2[50] = {0};
  comulative = 0;
  normal_fitness = 0;
  
  for (int i=0; i < popSize; i++){
    normal_fitness = (fitness[i]/sumFitness);
    comulative += normal_fitness;
    comulative_fitness[i] = comulative;
  }

  for(int i = 0; i < popSize; i += 2){

    p1 = roulette(sumFitness, popSize);
    p2 = roulette(sumFitness, popSize);

    for (int i = 0; i< lchrom; i++){
      om1[i] = population[p1][i];
      om2[i] = population[p2][i];
    }

    crossover(om1,om2);

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
  printf("\n\nchildreeeeenn =>\n\n");
  for(int i=0; i<popSize; i++) {
     printf("%d: ", i+1);
     for(int j=0; j<lchrom; j++) {
        printf("%d ", children[i][j]);
        if(j == (lchrom-1)){
           printf(" fitness => %f\n", fitness_children[i]);
        }
     }
  }

}

void nextGen(){
    //tabdil file children be parent
    for(int i=0; i<popSize; i++) {
       for(int j=0; j<lchrom; j++) {
          population[i][j] = children[i][j];
       }
    }
    //tabdile file fitness children be parent
    for(int i=0; i<popSize; i++) {
      fitness[i] = fitness_children[i];
    }
    printf("\n\nnewwww parentttttt =>\n\n");
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
