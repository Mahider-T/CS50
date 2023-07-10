import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect number of arguments, 2 are needed!")

    # TODO: Read database file into a variable
    header = [] #the colum headers and len(header) == number of columns
    database = [] #Info about all the people in the database
    with open(sys.argv[1], "r") as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            for i in range(len(row)):
                header.append(row[i])
            break
        # next(csv_reader)
        for row in csv_reader:
            person = {}
            for i in range(len(header)):
                person[header[i]] = row[i]
            database.append(person)
    # for i in database:
    #     print(i)

    # TODO: Read DNA sequence file into a variable
    string = " "
    with open(sys.argv[2], 'r') as f:
        string = f.read()
    # print(string)

    # TODO: Find longest match of each STR in DNA sequence
    target = []
    for i in range(1,len(header)):
        target.append(longest_match(string,header[i]))
    # print(target)

    # TODO: Check database for matching profiles
    for i in range(len(database)):
        isMatch = 0
        for j in range(1, len(header)):
            if int(database[i][header[j]]) == target[j - 1]:
                isMatch = 1
            else:
                isMatch = 0
                continue
            # print(database[i][header[j]], end = " ")
            # print(target[j - 1])
        if isMatch == 1:
            print(database[i]['name'])
            sys.exit(0)
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
