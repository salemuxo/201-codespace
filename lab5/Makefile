# ----------------------------------------
# Student's Name: Salem Stockdale
# Lab 5
# Lab Section: X03L
# Lab Instructor's Name: Salwa Abougamila
# Lecture Instructor's Name: Ardy RD
# ----------------------------------------

CC=gcc
CFLAGS=-Wall -std=c99
VGFLAGS=--leak-check=full --show-leak-kinds=all 

all: lab5E1 lab5E2

lab5E1: lab5E1.c dynamicArray.o
	$(CC) $(CFLAGS) -o lab5E1 lab5E1.c dynamicArray.o

dynamicArray.o: dynamicArray.c
	$(CC) $(CFLAGS) -c dynamicArray.c

lab5E2: lab5E2.c stuff.o
	$(CC) $(CFLAGS) -o lab5E2 lab5E2.c stuff.o

stuff.o: stuff.c
	$(CC) $(CFLAGS) -c stuff.c

valgrind: valgrindlab5E1 valgrindlab5E2

valgrindlab5E1: lab5E1
	valgrind $(VGFLAGS) ./lab5E1

valgrindlab5E2: lab5E2
	valgrind $(VGFLAGS) ./lab5E2

clean:
	rm *.o lab5E?

tar:
	tar -zcvf cmpt201_lab_5_SS.tar.gz dynamicArray.? lab5E?.c stuff.? Makefile