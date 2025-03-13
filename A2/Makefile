CC=gcc
CFLAGS=-Wall -std=c99 -g

all: pcode

pcode: pcode.c ht.o ht_impl.o 
	$(CC) $(CFLAGS) -o pcode pcode.c ht.o ht_impl.o

ht.o: ht.c
	$(CC) $(CFLAGS) -c ht.c

ht_impl.o: ht_impl.c
	$(CC) $(CFLAGS) -c ht_impl.c

# TESTING RULES

testing: compileTests testPrime testNode

compileTests: ht_impl.o
	$(CC) $(CFLAGS) -o testing/testPrime testing/testPrime.c ht_impl.o
	$(CC) $(CFLAGS) -o testing/testNode testing/testNode.c ht_impl.o 

testPrime: compileTests testing/testPrime.c ht_impl.o
	./testing/testPrime > testing/testPrimeOut
	diff testing/testPrimeOut testing/correctPrime

testNode: compileTests testing/testNode.c ht_impl.o
	./testing/testNode > testing/testNodeOut
	diff testing/testNodeOut testing/correctNode

# GENERAL RULES

clean:
	rm *.o pcode testing/*Out testing/testPrime testing/testNode