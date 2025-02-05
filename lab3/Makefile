CC=gcc
CFLAGS=-Wall -std=c99

all: lab3E1 lab3E2 lab3E3

lab3E1: lab3E1.c
	$(CC) $(CFLAGS) -o lab3E1 lab3E1.c

lab3E2: lab3E2.c
	$(CC) $(CFLAGS) -o lab3E2 lab3E2.c -lm

lab3E3: lab3E3.c change.o
	$(CC) $(CFLAGS) -o lab3E3 lab3E3.c change.o -lm

change.o: change.c
	$(CC) $(CFLAGS) -c change.c -lm

clean:
	rm *.o lab3E1 lab3E2 lab3E3

tar:
	tar -zcvf cmpt201_lab_3_SS.tar.gz Makefile lab3E1.c lab3E2.c lab3E3.c change.c change.h