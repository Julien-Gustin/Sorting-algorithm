/* ========================================================================= *
 * HeapSort
 * Implementation of the HeapSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void swap(int *array, int i, int j);
static int Left(int i);
static int Right(int i);
static void Max_Heapify(int *array, int i, size_t heap_size);
static void Build_Max_Heap(int *array, size_t length);

static int Left(int i){
  return 2*i;
}

static int Right(int i){
  return ((2*i)+1);
}

static void swap(int *array, int i, int j){
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

static void Max_Heapify(int *array, int i, size_t heap_size){
  int largest = 0;
  int l = Left(i);
  int r = Right(i);

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

  for(int i = length/2; i >= 0; i--)
    Max_Heapify(array, i, heap_size);
}

static void HeapSort(int *array, size_t length){
  Build_Max_Heap(array, length);
  size_t heap_size = length;

  for(int i = length; i >= 1; i--){
    swap(array, i , 0);
    heap_size--;
    Max_Heapify(array, 0, heap_size);
  }
}

void sort(int* array, size_t length){

  HeapSort(array, length-1);
}
