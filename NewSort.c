/* ========================================================================= *
 * NewSort
 * Implémentation de l'algorithme NewSort.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Fusionne deux sous tableau en un tableau : array[p..length]
 *
 * array[p..q] et array[q+1..length] sont trié
 *
 * PARAMETRES
 * array        Le tableau à trier
 * p            array[p..q-p+1], p <= q < length
 * q            array[q+1..length-q+1],
 * length       Nombres d'éléments dans le tableau (préé-condition: 0 <= length)
 * ------------------------------------------------------------------------- */
static void Merge(int* array, size_t p, size_t q, size_t length);

/* ------------------------------------------------------------------------- *
 * Trie un tableau d'entier.
 *
 * PARAMETRES
 * array        Le tableau à trier
 * length       Nombres d'éléments du tableau
 * ------------------------------------------------------------------------- */
static void NewSort(int* array, size_t length);

static void Merge(int* array, size_t p, size_t q, size_t length){
  assert(p <= q && q < length); // On ne peut pas avoir de tableau vide
  assert(length >= 0);

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

static void NewSort(int* array, size_t length){

  size_t i = 0;

  for(size_t j = 1; j < length; j++){ // Se déplace dans le tableau jusqu'à la dernière case
      while(array[j] <= array[j+1] && j < length-1) // 'j' est l'indice de la dernière case où array[i+1...j] est trié par ordre croissant
        j++;

      Merge(array, 0, i, j); // Fusionne 2 sous tableau déja trié pour que la fusion des deux soit lui aussi triée

      i = j;
  }
}

void sort(int* array, size_t length){
  if(array == NULL)
    return;

  NewSort(array, length);
}
