#include <stdio.h>
#include <math.h>


double eval(int chromosome[], int lchrom)
{
  int threats = 0;

  int total_posible_threats = ((lchrom * (lchrom - 1))/2); //C(2, lchrom)
  //printf("total threats = %d\n", total_posible_threats);

  for (int column = 0; column < lchrom; column++) {
      int column_value = chromosome[column];
      for (int pointer = column + 1; pointer < lchrom; pointer++) {
          int pointer_value = chromosome[pointer];
          if (column_value == pointer_value) { // in same row
              threats++;
          } else if (pointer - column == pointer_value - column_value) { // diagonal
              threats++;
          } else if (pointer - column == column_value - pointer_value) { // diagonal
              threats++;
          }
      }
  }
  //printf("number of threats = %d\n", threats);
  return (1 - (threats / (double)total_posible_threats));
}
