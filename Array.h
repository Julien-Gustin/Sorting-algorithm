/* ========================================================================= *
 * Array generator
 * ========================================================================= */

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
 * Create a sorted array of integers (from 0 to length-1).
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array (pre-condition: 0 < length)
 *
 * RETURN
 * array        A new array of integers, or NULL in case of error
 * ------------------------------------------------------------------------- */
int* createSortedArray(size_t length);

/* ------------------------------------------------------------------------- *
 * Create a random array of integers (from 0 to length-1).
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array (pre-condition: 0 < length)
 *
 * RETURN
 * array        A new array of integers, or NULL in case of error
 * ------------------------------------------------------------------------- */
int* createRandomArray(size_t length);

/* ------------------------------------------------------------------------- *
 * Create a random array of integers with k pre-sorted blocks.
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array (pre-condition: 0 < length)
 * k            Number of pre-sorted blocks (pre-condition: 0 < k <= length)
 *
 * RETURN
 * array        A new array of integers, or NULL in case of error
 * ------------------------------------------------------------------------- */
int* createRandomBlockArray(size_t length, size_t k);

#endif // !_ARRAY_H_
