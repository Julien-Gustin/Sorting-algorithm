#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "Array.h"
#include "Sort.h"

/* Prototypes */

/* ------------------------------------------------------------------------- *
 * Compute the CPU time (in seconds) used by the Sort function.
 *
 * PARAMETERS
 * array        Array to sort
 * length       Number of elements in the array
 *
 * RETURN
 * seconds      The number of seconds used by Sort
 * ------------------------------------------------------------------------- */
static double cpuTimeUsedToSort(int* array, size_t length)
{
    clock_t start = clock();
    sort(array, length);
    return ((double) (clock() - start)) / CLOCKS_PER_SEC;
}


/* ------------------------------------------------------------------------- *
 * Main
 * ------------------------------------------------------------------------- */
int main(int argc, char** argv)
{
   //--------------------------- PARSE COMMAND LINE -------------------------
    unsigned seed = (unsigned) time(NULL);
    size_t sizeArray = 10;
    bool useBlocks = false;
    size_t sizeBlocks = 5;
    int argi = 1; // Ideally this should be a size_t (historical reasons)
    while(argi < argc)
    {
        if(strcmp(argv[argi], "-s") == 0)
        {
            size_t inputSize;
            if(sscanf (argv[++argi], "%zu", &inputSize) != 1)
            {
                fprintf(stderr, "%s\n", "Aborting; size should be an unsigned "
                                        "integer.");
                exit(EXIT_FAILURE);
            }
            sizeArray = inputSize;
        } else if(strcmp(argv[argi], "-r") == 0) {
            unsigned inputSeed;
            if(sscanf (argv[++argi], "%u", &inputSeed) != 1)
            {
                fprintf(stderr, "%s\n", "Aborting; the random seed should be an "
                                        "unsigned integer.");
                exit(EXIT_FAILURE);
            }
            seed = inputSeed;
        } else if(strcmp(argv[argi], "-b") == 0) {
            size_t inputSizeBlocks;
            if(sscanf (argv[++argi], "%zu", &inputSizeBlocks) != 1)
            {
                fprintf(stderr, "%s\n", "Aborting; size should be an unsigned "
                                        "integer.");
                exit(EXIT_FAILURE);
            }
            sizeBlocks = inputSizeBlocks;
            useBlocks = true;
        } else {
            fprintf(stderr, "%s '%s'\n", "Aborting; unknown parameter",
                    argv[argi]);
            fprintf(stderr, "%s %s %s\n", "Usage:", argv[0], "[-s size] "
                    "[-r random_seed] [-b sizeBlocks]\n"
                    "-b can be omitted for random instead of random blocks array.");
            exit(EXIT_FAILURE);
        }
        argi++;
    }

    if (sizeArray < sizeBlocks) {
        sizeArray = sizeBlocks;
    }

    srand(seed);//Use an integer seed to get a fix sequence

    printf("Size of the array: %d\n", (int) sizeArray);
    int* array;

    if (useBlocks)
        array = createRandomBlockArray(sizeArray, sizeBlocks);
    else
        array = createRandomArray(sizeArray);


    const double sec = cpuTimeUsedToSort(array, sizeArray);
    printf("\nCPU Time: %f\n\n", sec);

    free(array);

    return 0;
}
