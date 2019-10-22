/* ========================================================================= *
 * HeapSort
 * Implémentation ode l'algorithme HeapSort.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include "Sort.h"

/* ------------------------------------------------------------------------- *
 * Echange les éléments du tableau array[i] avec array[j] tel que, array[i] <=> array[j]
 *
 * PARAMETRES
 * array        Tableau d'entier
 * i            Indice du premier éléments
 * j            Indice du second éléments
 * ------------------------------------------------------------------------- */
static void swap(int *array, size_t i, size_t j);

/* ------------------------------------------------------------------------- *
 * Retourne le fils gauche du noeud i de l'arbre binaire
 *
 * PARAMETRES
 * i       Le noeud i de l'arbre binaire
 * ------------------------------------------------------------------------- */
static size_t Left(size_t i);

/* ------------------------------------------------------------------------- *
 * Retourne le fils droit du noeud i de l'arbre binaire
 *
 * PARAMETRES
 * i       Le noeud i de l'arbre binaire
 * ------------------------------------------------------------------------- */
static size_t Right(size_t i);

/* ------------------------------------------------------------------------- *
 * Rétablit la propriété des tas(pour tout i, en tenant compte du fait que les
 * sous-arbres de droite et de gauche sont des tas
 *
 * PARAMETRES
 * array        Tableau d'entier
 * heap_size     La taille du tas
 * ------------------------------------------------------------------------- */
static void Max_Heapify(int *array, size_t i, size_t heap_size);

/* ------------------------------------------------------------------------- *
 * Construit un tas (arbre binaire)à partir du tableau à trier
 *
 * PARAMETRES
 * array        Tableau d'entier
 * length       La taille du tableau
 * ------------------------------------------------------------------------- */
static void Build_Max_Heap(int *array, size_t length);

/* ------------------------------------------------------------------------- *
 * Trie un tableau d'entier.
 *
 * PARAMETRES
 * array        Le tableau à trier
 * length       La taille du tableau
 * ------------------------------------------------------------------------- */
static void HeapSort(int *array, size_t length);

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
  if(array == NULL || length == 0)
    return;
  HeapSort(array, length-1);
}
