import csv
from collections import Counter

with open("testing/covidData.csv", "r") as file:
    csv_reader = csv.reader(file)
    next(csv_reader)
    dates = []

    for row in csv_reader:
        dates.append(row[1])

with open("testing/correctCountingCovid.txt", "w") as file:
    date_counts = Counter(dates)
    for date, count in date_counts.items():
        if count > 0:
            file.write(f"{date}: {count}\n")