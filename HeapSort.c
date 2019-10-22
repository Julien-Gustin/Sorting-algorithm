/* ========================================================================= *
 * HeapSort
 * Implémentation ode l'algorithme HeapSort.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void swap(int *array, size_t i, size_t j);
static size_t Left(size_t i);
static size_t Right(size_t i);
static void Max_Heapify(int *array, size_t i, size_t heap_size);
static void Build_Max_Heap(int *array, size_t length);

static size_t Left(size_t i){
  return 2*i;
}

static size_t Right(size_t i){
  return ((2*i)+1);
}

static void swap(int *array, size_t i, size_t j){
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

static void Max_Heapify(int *array, size_t i, size_t heap_size){
  size_t largest = 0;
  size_t l = Left(i);
  size_t r = Right(i);

  if(l <= heap_size && array[l] > array[i])
    largest = l;

  else
    largest = i;

  if(r <= heap_size && array[r] > array[largest])
    largest = r;

  if(largest != i){
    swap(array, i, largest);
    Max_Heapify(array, largest, heap_size);
  }
}

static void Build_Max_Heap(int *array, size_t length){
  size_t heap_size = length;

  for(int i = length/2; i >= 0; i--) // int parce que à la fin de la boucle i = -1
    Max_Heapify(array, i, heap_size);
}

static void HeapSort(int *array, size_t length){
  Build_Max_Heap(array, length);
  size_t heap_size = length;

  for(size_t i = length; i >= 1; i--){
    swap(array, i , 0);
    heap_size--;
    Max_Heapify(array, 0, heap_size);
  }
}

void sort(int* array, size_t length){

  HeapSort(array, length-1);

}
