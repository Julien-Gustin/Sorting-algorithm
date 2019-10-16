/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void QuickSort(int *array, int p, int r);
static int partition(int *array, int p, int r);
static void swap(int *array, int i, int j);

static void swap(int *array, int i, int j){
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}
static int partition(int *array, int p, int r){
  int x = array[r];
  int i = p-1;
  for(int j = p; j < r; j++){
    if(array[j] <= x){
      i++;
      swap(array, i, j);
    }

  }
  swap(array, i+1, r);
  return i+1;

}



static void QuickSort(int *array, int p, int r){
  if(p < r){
    int q = partition(array, p, r);
    QuickSort(array, p, q-1);
    QuickSort(array, q+1, r);

  }

}

void sort(int* array, size_t length){

  for(unsigned long i = 0; i < length; i++)
    printf("[%d]", array[i]);

  printf("\n\n");

  QuickSort(array, 0, length-1);

  for(unsigned long i = 0; i < length; i++)
    printf("%d:[%d]", i, array[i]);

    for(size_t i = 0; i <length-1; i++){
      if(array[i] > array[i+1])
        printf("ERREUR %d", i);

  }

  }
