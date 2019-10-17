/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void Merge(int* array, int p, int q, size_t length){
  int n1 = q - p + 1;
  int n2 = length - q;
  int *L = malloc(sizeof(int) *(n1+1));
  if(L == NULL)
    return ;

  int *R = malloc(sizeof(int) *(n2+1));
  if(R == NULL)
    return;

  for(int i = 0; i < n1; i++)
    L[i] = array[p+i];

  for(int j = 0; j < n2; j++)
    R[j] = array[q+j+1];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int i = 0;
  int j = 0;

  for(unsigned long k = p; k <= length; k++){
    if(L[i] <= R[j]){
      array[k] = L[i];
      i++;
    }
    else{
      array[k] = R[j];
      j++;
    }

  }

  free(L);
  free(R);
}


void sort(int* array, size_t length){

  size_t i = 0; // changer en size t

  for(size_t j = 1; j < length; j++){
      while(array[j] < array[j+1] && j < length-1)
        j++;

        Merge(array, 0, i, j);

      i = j;
  }


}
