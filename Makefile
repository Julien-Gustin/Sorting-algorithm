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
MODULES_TRI=main.c Array.c QuickSort.c
OBJECTS_TRI=main.o Array.o QuickSort.c


EXEC_ALL=main

## Rules

############# TRI #############

main: $(OBJECTS_TRI)
	$(LD) -o $(EXEC_TRI) $(OBJECTS_TRI)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

Array.o: Array.c
	$(CC) -c Array.c -o Array.o $(CFLAGS)

QuickSort.o: QuickSort.c
	$(CC) -c QuickSort.c -o QuickSort.o $(CFLAGS)


clean:
	rm -f *.o $(EXEC_ALL) *~
