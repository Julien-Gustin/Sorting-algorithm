/* ========================================================================= *
 * QuickSort
 * Implementation of the Quick algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Sort an array of integers.
 *
 * PARAMETERS
 * array        The array to sort
 * p
 * r
 * ------------------------------------------------------------------------- */
static void QuickSort(int *array, int p, int r);
/* ------------------------------------------------------------------------- *
 * Swap all the elements <= pivot, to the begging of the under array
 *
 * PARAMETERS
 * array        array of integers
 * p            Index
 * Ipivot       Is the indice of the pivot
 *
 * RETURN
 * i+1          index of the last element
 * ------------------------------------------------------------------------- */
static int partition(int *array, int p, size_t Ipivot);
/* ------------------------------------------------------------------------- *
 * Swap the element of array[i] with array[j], array[i] <=> array[j]
 *
 * PARAMETERS
 * array        array of integers
 * i            Index of the first element
 * j            Index of the seconds element
 * ------------------------------------------------------------------------- */
static void swap(int *array, size_t i, size_t j);

static void swap(int *array, size_t i, size_t j){
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}
static int partition(int *array, int p, size_t Ipivot){
  int pivot = array[Ipivot];
  size_t i = p-1;
  for(size_t j = p; j < Ipivot; j++){ // all the elements <= of the pivot are placed at the beginning of the under-array;
    if(array[j] <= pivot){
      i++;
      swap(array, i, j);
    }
  }

  swap(array, i+1, Ipivot); // the pivot is swapped to the end of the swapped elements.
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

  QuickSort(array, 0, length-1);

  }
