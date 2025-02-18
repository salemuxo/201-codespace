"""-------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
-------------------------------------"""

with open("testing/testCardinalSortIn.txt", "r") as input, open("testing/correctCardinalSort.txt", "w") as output:
    for line in input:
        output.write("".join(sorted(line.strip())) + "\n")