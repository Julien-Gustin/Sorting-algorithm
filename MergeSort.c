/* ========================================================================= *
 * MergeSort
 * Implémentation de l'algorithme MergeSort.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Trie un tableau d'entier.
 *
 * PARAMETRES
 * array        Le tableau à trier
 * p            l'indice du premier élément du tableau
 * length       Nombres d'éléments du tableau
 * ------------------------------------------------------------------------- */
static void MergeSort(int* array, size_t p, size_t length);

/* ------------------------------------------------------------------------- *
 * Fusionne deux sous tableau en un meme tableau array[p..length]
 *
 * array[p..q] et array[q+1..length] sont triée
 *
 * PARAMETRES
 * array        Le tableau à trier
 * p            array[p..q-p+1], p <= q < length
 * q            array[q+1..length-q+1],
 * length       Nombres d'éléments du tableau (0 <= length)
 * ------------------------------------------------------------------------- */
static void Merge(int* array, size_t p, size_t q, size_t length);

static void Merge(int* array, size_t p, size_t q, size_t length){
  assert(p <= q && q < length); // On ne peut pas avoir de tableau vide
  assert(length > 0);

  size_t n1 = q - p + 1;
  size_t n2 = length - q;
  int *L = malloc(sizeof(int) *(n1+1)); // la dernière case du tableau est réservé pour le dernier entier possible
  if(L == NULL)
    return;

  int *R = malloc(sizeof(int) *(n2+1)); // la dernière case du tableau est réservé pour le dernier entier possible
  if(R == NULL)
    return;

  for(size_t i = 0; i < n1; i++) // copie une partie du tableau tel que : L[] = array[p..p+n1]
    L[i] = array[p+i];

  for(size_t j = 0; j < n2; j++) // copie une partie du tableau tel que : R[] = array[q+1..q+n2+1]
    R[j] = array[q+j+1];

  L[n1] = INT_MAX; // Parce que rien n'est plus grand que INT_MAX
  R[n2] = INT_MAX;

  int i = 0;
  int j = 0;

  for(unsigned long k = p; k <= length; k++){ // Fusion
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

  if(p < length){
    size_t q = (length+p)/2; // Scinde le tableau en deux
    MergeSort(array, p, q);
    MergeSort(array, q+1, length);

    Merge(array, p, q, length); // Fusionne deux sous tableaux déjà trié
  }
}

void sort(int* array, size_t length){
  if(array == NULL || length == 0)
    return;

  MergeSort(array, 0, length-1); //array[0..length-1]
  }
