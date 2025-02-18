with open("testing/testCardinalSortIn.txt", "r")as input, open("testing/correctCardinalSort.txt", "w") as output:
    for line in input:
        output.write("".join(sorted(line.strip())) + "\n")