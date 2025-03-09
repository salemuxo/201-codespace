CC=gcc
CFLAGS=-Wall -std=c99 -g

lab6E1: lab6E1.o link.o
	$(CC) $(CFLAGS) -o lab6E1 lab6E1.o link.o

lab6E1.o: lab6E1.c
	$(CC) $(CFLAGS) -c lab6E1.c

link.o: link.c
	$(CC) $(CFLAGS) -c link.c

clean:
	rm *.o lab6E1