CC=gcc
CFLAGS=-Wall -std=c99 -g

all: pcode

pcode: pcode.c ht.o ht_impl.o 
	$(CC) $(CFLAGS) -o pcode pcode.c ht.o ht_impl.o

ht.o: ht.c
	$(CC) $(CFLAGS) -c ht.c

ht_impl.o: ht_impl.c ht.h
	$(CC) $(CFLAGS) -c ht_impl.c

# TESTING RULES

testing: compileTests testPrime testEntry testInsertDelete

compileTests: ht_impl.o ht.o
	$(CC) $(CFLAGS) -o testing/testPrime ht.o ht_impl.o testing/testPrime.c 
	$(CC) $(CFLAGS) -o testing/testEntry ht.o ht_impl.o  testing/testEntry.c
	$(CC) $(CFLAGS) -o testing/testInsertDelete ht.o ht_impl.o testing/testInsertDelete.c

testPrime: compileTests
	./testing/testPrime > testing/testPrimeOut
	diff testing/testPrimeOut testing/correctPrime

testEntry: compileTests
	./testing/testEntry > testing/testEntryOut
	diff testing/testEntryOut testing/correctEntry

testInsertDelete: compileTests 
	./testing/testInsertDelete > testing/testInsertDeleteOut
	diff testing/testInsertDeleteOut testing/correctInsertDelete

# GENERAL RULES

clean:
	rm *.o pcode testing/*Out testing/testPrime testing/testEntry