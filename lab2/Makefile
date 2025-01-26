# lab2: main.c numMod.c numArray.c99
# 	gcc –Wall –std=c99 main.c numArray.c numMod.c –o lab2 -lm

CC=gcc
CFLAGS=-Wall -std=c99
LDLIBS=-lm

lab2: main.o numMod.o numArray.o
	$(CC) $(CFLAGS) -o lab2 main.o numArray.o numMod.o $(LDLIBS)

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

numMod.o: numMod.c
	$(CC) $(CFLAGS) -c numMod.c

numArray.o: numArray.c
	$(CC) $(CFLAGS) -c numArray.c

testing:
	./lab2 < testLab2In > testLab2Out
	diff lab2Correct testLab2Out

clean:
	rm *.o lab2 testLab2Out

tar: 
	tar -zcvf cmpt201_lab_2_SS.tar.gz Makefile main.c numArray.c numArray.h numMod.c numMod.h README lab2Correct testLab2In