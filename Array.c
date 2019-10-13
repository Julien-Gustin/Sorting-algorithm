/* ========================================================================= *
 * Array generator
 * Implementation of the Array generator interface
 * ========================================================================= */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "Array.h"

static const int MAX_START = 1001;
static const int UPPER_BOUND = 1001;

static int __compare(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}

int* createSortedArray(size_t length)
{
    int* array = (int*) malloc(length * sizeof(int));

    if (array == NULL)
    {
        return NULL;
    }
    int shift = rand() % MAX_START;
    for (size_t i = 0; i < length; i++)
    {
        array[i] = shift + i;
    }

    return array;
}

int* createRandomArray(size_t length)
{
    if (length == 0)
      return NULL;
    int* array = (int*) malloc(length * sizeof(int));

    if (array == NULL)
        return NULL;

    for (size_t i = 0; i < length; i++)
        array[i] = rand() % UPPER_BOUND;

    return array;
}

int* createRandomBlockArray(size_t length, size_t k)
{
    int* randomBlockArray = createRandomArray(length);
    if (randomBlockArray == NULL)
        return NULL;

    int boundaries[k];
    size_t potentialBoundaries[length - 1];

    //Generate the boundaries with no duplicate. It cannot be 0 or length-1
    size_t maxPotentialIndex = length - 1;
    for (size_t i = 0; i < maxPotentialIndex; i++)
        potentialBoundaries[i] = i+1;
    size_t index = 0;
    for (size_t i = 0; i < k-1; i++)
    {
        index = (size_t) (rand() % maxPotentialIndex);
        boundaries[i] = potentialBoundaries[index];
        potentialBoundaries[index] = potentialBoundaries[maxPotentialIndex-1];
        maxPotentialIndex--;
    }
    //Sort boundaries
    qsort(boundaries, k-1, sizeof(int), __compare);
    boundaries[k-1] = length - 1;//Add last boundaries

    //Sort by block
    size_t start = 0;//Included
    size_t end;//Included
    size_t blockSize;
    for(size_t i = 0; i < k; i++)
    {
        end = (size_t)boundaries[i];
        blockSize = (end - start) + 1;
        qsort(randomBlockArray + start, blockSize, sizeof(int), __compare);
        if (start > 0) { // to make sure two consecutive blocks are not sorted
            int prev = randomBlockArray[start - 1];
            if (prev <= randomBlockArray[start]) {
                randomBlockArray[start] = prev - 1;
            }
        }
        start = end + 1;
    }
    return randomBlockArray;
}
