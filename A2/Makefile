CC=gcc
CFLAGS=-Wall -std=c99

all: pcode

pcode: pcode.c ht.o ht_impl.o 
	$(CC) $(CFLAGS) -o pcode pcode.c ht.o ht_impl.o

ht.o: ht.c
	$(CC) $(CFLAGS) -c ht.c

ht_impl.o: ht_impl.c
	$(CC) $(CFLAGS) -c ht_impl.c

testing: testPrime testNode

compileTests:

testPrime: testing/testPrime.c ht_impl.o
	$(CC) $(CFLAGS) -o testing/testPrime testing/testPrime.c ht_impl.o
	./testing/testPrime > testing/testPrimeOut
	diff testing/testPrimeOut testing/correctPrime

testNode: testing/testNode.c ht_impl.o
	$(CC) $(CFLAGS) -o testing/testNode testing/testNode.c ht_impl.o 
	./testing/testNode > testing/testNodeOut
	diff

clean:
	rm *.o pcode testing/*Out testing/testPrime