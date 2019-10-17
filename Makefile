###
## Makefile skeleton
## INFO0030: Projet 2
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -Wextra -Wmissing-prototypes
LD=gcc

# Files
EXEC_TRI=main
<<<<<<< HEAD
MODULES_TRI=main.c Array.c NewSort.c
OBJECTS_TRI=main.o Array.o NewSort.c
=======
MODULES_TRI=main.c Array.c HeapSort.c
OBJECTS_TRI=main.o Array.o HeapSort.c
>>>>>>> 9b25b162fda819f60dd62be98d7b18ca3bd34aed


EXEC_ALL=main

## Rules

############# TRI #############

main: $(OBJECTS_TRI)
	$(LD) -o $(EXEC_TRI) $(OBJECTS_TRI)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

Array.o: Array.c
	$(CC) -c Array.c -o Array.o $(CFLAGS)

<<<<<<< HEAD
NewSort.o: NewSort.c
	$(CC) -c NewSort.c -o NewSort.o $(CFLAGS)
=======
HeapSort.o: HeapSort.c
	$(CC) -c HeapSort.c -o HeapSort.o $(CFLAGS)
>>>>>>> 9b25b162fda819f60dd62be98d7b18ca3bd34aed


clean:
	rm -f *.o $(EXEC_ALL) *~
