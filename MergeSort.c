/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Create a sorted array of integers (from 0 to length-1).
 *
 * PARAMETERS
 * array        The array to sort
 * p            Is the indice of the first element of the array
 * length       Number of elements in the array (pre-condition: 0 <= length)
 * ------------------------------------------------------------------------- */
static void MergeSort(int* array, size_t p, size_t length);

/* ------------------------------------------------------------------------- *
 * Merge two under array in one array array[p..length]
 *
 * array[p..q] and array[q+1..length] are sort
 *
 * PARAMETERS
 * array        The array to sort
 * p            array[p..q-p+1], p <= q < length
 * q            array[q+1..length-q+1],
 * length       Number of elements in the array (pre-condition: 0 <= length)
 * ------------------------------------------------------------------------- */
static void Merge(int* array, size_t p, size_t q, size_t length);

static void Merge(int* array, size_t p, size_t q, size_t length){
  assert(p <= q && q < length); // no empty array
  assert(length >= 0);

  size_t n1 = q - p + 1;
  size_t n2 = length - q;
  int *L = malloc(sizeof(int) *(n1+1)); // the (n1+1)th is use for the biggest int
  if(L == NULL)
    return;

  int *R = malloc(sizeof(int) *(n2+1)); // the (n2+1)th is use for the biggest int
  if(R == NULL)
    return;

  for(size_t i = 0; i < n1; i++) // copping a part of the array like L[] = array[p..p+n1]
    L[i] = array[p+i];

  for(size_t j = 0; j < n2; j++) // copping a part of the array like R[] = array[q+1..q+n2+1]
    R[j] = array[q+j+1];

  L[n1] = INT_MAX; // because nothings is > than INT_MAX
  R[n2] = INT_MAX; // because nothings is > than INT_MAX

  int i = 0;
  int j = 0;

  for(unsigned long k = p; k <= length; k++){ // Merging
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

static void MergeSort(int* array, size_t p, size_t length){
  assert(length >= 0);

  if(p < length){
    size_t q = (length+p)/2; // splits the array in two
    MergeSort(array, p, q);
    MergeSort(array, q+1, length);

    Merge(array, p, q, length); // Merge 2 under array already sorted, such that array[p..q] is sorted as well as array[q+1..length], and Merge returns a sorted array up to index length ( array[0..length] )
  }
}

void sort(int* array, size_t length){
  MergeSort(array, 0, length-1); //array[0..length-1]

  }
