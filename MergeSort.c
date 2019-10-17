/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void MergeSort(int* array, unsigned long p, size_t length);
static void Merge(int* array, int p, int q, size_t length);

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

static void MergeSort(int* array, unsigned long p, size_t length){
  if(p < length){
    int q = (length+p)/2;


    MergeSort(array, p, q);
    MergeSort(array, q+1, length);
    Merge(array, p, q, length);
  }
}

void sort(int* array, size_t length){

  MergeSort(array, 0, length-1);

  }
