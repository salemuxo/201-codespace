CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lm

# executable rules

all: cardinalSort countingCovid squeeze xTable

cardinalSort: cardinalSort.c 
	$(CC) $(CFLAGS) cardinalSort.c -o cardinalSort

countingCovid: countingCovid.c
	$(CC) $(CFLAGS) countingCovid.c -o countingCovid

squeeze: squeeze.c
	$(CC) $(CFLAGS) squeeze.c -o squeeze

xTable: xTable.c
	$(CC) $(CFLAGS) xTable.c -o xTable

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
	./xTable < testing/testXTableIn.txt > testing/testXTableOut.txt

# other rules

clean:
	rm cardinalSort countingCovid squeeze xTable testing/testCardinalSortOut.txt testing/testCountingCovidOut.txt testing/testSqueezeOut.txt testing/testXTableOut.txt

tar:
	tar -zcvf cmpt201_a1_SS.tar.gz Makefile countingCovid.c squeeze.c