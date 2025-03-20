CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lm

all: lab7E1

lab7E1: lab7E1.c
	$(CC) $(CFLAGS) -o lab7E1 lab7E1.c $(LDFLAGS)

clean:
	rm lab7E1 out.bin

tar:
	tar -zcvf cmpt201_lab_7_SS.tar.gz lab7E1.c Makefile