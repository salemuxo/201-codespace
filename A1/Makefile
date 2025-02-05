CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lm

# executable rules

all: countingCovid squeeze

countingCovid: countingCovid.c
	$(CC) $(CFLAGS) countingCovid.c -o countingCovid

squeeze: squeeze.c
	$(CC) $(CFLAGS) squeeze.c -o squeeze

# testing rules

testing: testCountingCovid

testCountingCovid: countingCovid
	./countingCovid < testing/covidData.csv > testing/testCountingCovidOut.txt
	diff testing/testCountingCovidOut.txt testing/correctCountingCovid.txt


clean:
	rm countingCovid squeeze testing/testCountingCovidOut

tar:
	tar -zcvf cmpt201_a1_SS.tar.gz Makefile countingCovid.c squeeze.c