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
	$(CC) $(CFLAGS) -o cardinalSort cardinalSort.c 

countingCovid: countingCovid.c
	$(CC) $(CFLAGS) -o countingCovid countingCovid.c

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
	python testing/testCardinalSort.py 
	diff testing/testCardinalSortOut.txt testing/correctCardinalSort.txt

testCountingCovid: countingCovid
	./countingCovid < testing/covidData.csv > testing/testCountingCovidOut.txt
	python testing/testCountingCovid.py
	diff testing/testCountingCovidOut.txt testing/correctCountingCovid.txt

testSqueeze: squeeze
	./squeeze < testing/testSqueezeIn.txt > testing/testSqueezeOut.txt
	diff testing/testSqueezeOut.txt testing/correctSqueeze.txt

testXTable: xTable
	./xTable > testing/testXTableOut.txt
	diff testing/testXTableOut.txt testing/correctXTable.txt

# other rules

clean:
	rm *.o cardinalSort countingCovid squeeze xTable testing/test*Out.txt testing/correctCardinalSort.txt testing/correctCountingCovid.txt

tar:
	tar -zcvf cmpt201_a1_SS.tar.gz Makefile cardinalSort.c countingCovid.c squeeze.c xTable.c xTableHelpers.c xTableHelpers.h testing