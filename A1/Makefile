# /*--------------------------------------
# Student's Name: Salem Stockdale
# Assignment 1
# Lab Section: X03L
# Lab Instructor's Name: Salwa Abougamila
# Lecture Instructor's Name: Ardy RD
# --------------------------------------*/


CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lm

# executable rules

all: cardinalSort countingCovid squeeze xTable

cardinalSort: cardinalSort.c 
	$(CC) $(CFLAGS) cardinalSort.c -o cardinalSort

countingCovid: countingCovid.o countingCovidHelpers.o
	$(CC) $(CFLAGS) -o countingCovid countingCovid.o countingCovidHelpers.o

countingCovid.o: countingCovid.c countingCovidHelpers.o
	$(CC) $(CFLAGS) -c countingCovid.c

countingCovidHelpers.o: countingCovidHelpers.c
	$(CC) $(CFLAGS) -c countingCovidHelpers.c

squeeze: squeeze.c
	$(CC) $(CFLAGS) squeeze.c -o squeeze

xTable: xTable.o xTableHelpers.o
	$(CC) $(CFLAGS) -o xTable xTable.o xTableHelpers.o $(LDFLAGS)

xTable.o: xTable.c xTableHelpers.o
	$(CC) $(CFLAGS) -c xTable.c

xTableHelpers.o: xTableHelpers.c 
	$(CC) $(CFLAGS) -c xTableHelpers.c

# testing rules

testing: testCardinalSort testCountingCovid testSqueeze testXTable

testCardinalSort: cardinalSort
	./cardinalSort < testing/testCardinalSortIn.txt > testing/testCardinalSortOut.txt

testCountingCovid: countingCovid
	./countingCovid < testing/covidData.csv > testing/testCountingCovidOut.txt
	diff testing/testCountingCovidOut.txt testing/correctCountingCovid.txt

testSqueeze: squeeze
	./squeeze < testing/testSqueezeIn.txt > testing/testSqueezeOut.txt

testXTable: xTable
	./xTable > testing/testXTableOut.txt
	diff testing/testXTableOut.txt testing/correctXTable.txt

# other rules

clean:
	rm *.o cardinalSort countingCovid squeeze xTable testing/testCardinalSortOut.txt testing/testCountingCovidOut.txt testing/testSqueezeOut.txt testing/testXTableOut.txt

tar:
	tar -zcvf cmpt201_a1_SS.tar.gz Makefile countingCovid.c squeeze.c