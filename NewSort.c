/* ========================================================================= *
 * NewSort
 * Implementation of the NewSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void Merge(int* array, int p, int q, size_t length){
  int n1 = q - p + 1;
  int n2 = length - q;
  int *L = malloc(sizeof(int) *(n1+1));
  if(L == NULL)
    return ;

  int *R = malloc(sizeof(int) *(n2+1));
  if(R == NULL)
    return;

  for(size_t i = 0; i < n1; i++)
    L[i] = array[p+i];

  for(size_t j = 0; j < n2; j++)
    R[j] = array[q+j+1];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  size_t i = 0;
  size_t j = 0;

  for(size_t k = p; k <= length; k++){
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


void sort(int* array, size_t length){

  size_t i = 0;

  for(size_t j = 1; j < length; j++){ // Parcours le tableau jusqu'à sa dernière case
      while(array[j] <= array[j+1] && j < length-1) //l'indice j doit etre l'indice de la derniere case ou le tableau array[i+1..j] est trié par ordre croissant
        j++;

      Merge(array, 0, i, j); // Trie 2 sous tableau déja trié, tel que array[0..i] est trié et array[i+1..j] est trié, et l'output de Merge renvois un tableau trié jusqu'à l'indice j ( array[0..j] )

      i = j;
  }


}
