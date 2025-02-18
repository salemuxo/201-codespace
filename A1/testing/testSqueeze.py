"""-------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
-------------------------------------"""

from itertools import groupby

with open("testing/testSqueezeIn.txt", "r") as input, open("testing/correctSqueeze.txt", "w") as output:
    for line in input:
        # group line into array of strings split by character
        grouped = ["".join(group) for key, group in groupby(line.strip())]
        for group in grouped:
            char = group[0]
            count = len(group)

            # if only one, just print character
            if count == 1:
                output.write(group[0])
            else:
                # write character and count to file, splitting by increments of 9
                for i in range(count // 9):
                    output.write(f"{group[0]}9")
                output.write(f"{group[0]}{count % 9}")                
        output.write("\n")