CC=gcc
CFLAGS=-Wall -std=c99 -g
LDFLAGS=-lm
VGFLAGS=--leak-check=full --show-leak-kinds=all

all: pcode testing

pcode: pcode.c ht.o ht_impl.o 
	$(CC) $(CFLAGS) $(LDFLAGS) -o pcode pcode.c ht.o ht_impl.o

ht.o: ht.c
	$(CC) $(CFLAGS) -c ht.c

ht_impl.o: ht_impl.c ht.h
	$(CC) $(CFLAGS) -c ht_impl.c

# TESTING RULES

testing: compileTests testPrime testEntry testInsertDelete testDist valgrindTests

compileTests: ht_impl.o ht.o
	$(CC) $(CFLAGS) -o testing/testPrime ht.o ht_impl.o testing/testPrime.c 
	$(CC) $(CFLAGS) -o testing/testEntry ht.o ht_impl.o  testing/testEntry.c
	$(CC) $(CFLAGS) -o testing/testInsertDelete ht.o ht_impl.o testing/testInsertDelete.c
	$(CC) $(CFLAGS) -o testing/testDist ht.o ht_impl.o testing/testDist.c

testPrime: compileTests
	./testing/testPrime > testing/testPrimeOut
	diff testing/testPrimeOut testing/correctPrime

testEntry: compileTests
	./testing/testEntry > testing/testEntryOut
	diff testing/testEntryOut testing/correctEntry

testInsertDelete: compileTests 
	./testing/testInsertDelete > testing/testInsertDeleteOut
	diff testing/testInsertDeleteOut testing/correctInsertDelete

testDist: compileTests
	./testing/testDist > testing/testDistOut

# VALGRIND RULES

valgrindPcode: pcode
	valgrind $(VGFLAGS) ./pcode ./datasets/postalcodes.in

valgrindTests: compileTests valgrindTestPrime valgrindTestEntry valgrindTestInsertDelete valgrindTestDist

valgrindTestPrime: compileTests
	valgrind $(VGFLAGS) ./testing/testPrime

valgrindTestEntry: compileTests
	valgrind $(VGFLAGS) ./testing/testEntry

valgrindTestInsertDelete: compileTests
	valgrind $(VGFLAGS) ./testing/testInsertDelete

valgrindTestDist: compileTests
	valgrind $(VGFLAGS) ./testing/testDist

# GENERAL RULES

clean:
	rm *.o pcode testing/*Out testing/testPrime testing/testEntry testing/testInsertDelete testing/testDist

tar:
	tar -zcvf cmpt201_a2_SS.tar.gz Makefile pcode.c ht.? ht_impl.? testing/test*.c testing/correct* "testing/Testing Strategy Document"