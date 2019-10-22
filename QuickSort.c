/* ========================================================================= *
 * QuickSort
 * Implémentation de l'algorithme QuickSort.
 * ========================================================================= */

#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Trie un tableau d'entier.
 *
 * PARAMETRES
 * array        Le tableau à trier
 * p
 * r
 * ------------------------------------------------------------------------- */
static void QuickSort(int *array, int p, int r);
/* ------------------------------------------------------------------------- *
 * Déplace tout les éléments plus petit ou égale au pivot, au début du sous tableau
 *
 * PARAMETRES
 * array        Tableau d'entier
 * p            Indice
 * Ipivot       L'indice du pivot
 *
 * RETOURNE
 * i+1          Indice du dernier éléments
 * ------------------------------------------------------------------------- */
static int partition(int *array, int p, size_t Ipivot);
/* ------------------------------------------------------------------------- *
 * Echange les éléments du tableau array[i] avec array[j] tel que, array[i] <=> array[j]
 *
 * PARAMETRES
 * array        Tableau d'entier
 * i            Indice du premier éléments
 * j            Indice du second éléments
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
  for(size_t j = p; j < Ipivot; j++){ // Tout les éléments <= au pivot sont placés au début du sous tableau
    if(array[j] <= pivot){
      i++;
      swap(array, i, j);
    }
  }

  swap(array, i+1, Ipivot); // On swap le pivot avec le dernier élément swapé
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
  if(array == NULL)
    return;

  QuickSort(array, 0, length-1);
  }
