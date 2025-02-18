"""-------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
-------------------------------------"""

from csv import reader
from collections import Counter

with open("testing/covidData.csv", "r") as input, open("testing/correctCountingCovid.txt", "w") as output:
    # write all dates to list
    csv_reader = reader(input)
    next(csv_reader)
    dates = []

    for row in csv_reader:
        dates.append(row[1])

    # count repeated dates and write to output
    date_counts = Counter(dates)
    for date, count in date_counts.items():
        if count > 0:
            output.write(f"{date}: {count}\n")