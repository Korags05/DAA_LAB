/*
Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file.
Note# Read the value of ‘n’, source file name and destination file name from command line
arguments. Display the decimal numbers and their equivalent binary numbers from the output
file.
Give the contents of the input disc file “inDec.dat” as
30 75 2564 …
Contents of the output disc file “outBin.dat” as
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat
Output: Content of the first ‘n’ decimal and their equivalent binary numbers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 16

// Recursive function to convert decimal to binary string
void decToBin(int num, char *binStr, int index) {
    if (index < 0) return;
    binStr[index] = (num % 2) + '0';
    decToBin(num / 2, binStr, index - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    int count = 0, num;
    while (count < n && fscanf(in, "%d", &num) == 1) {
        char binStr[MAX_BITS + 1];
        binStr[MAX_BITS] = '\0';

        decToBin(num, binStr, MAX_BITS - 1);

        fprintf(out, "The binary equivalent of %d is %s\n", num, binStr);
        count++;
    }

    fclose(in);
    fclose(out);

    // Display output file content
    out = fopen(outputFile, "r");
    if (!out) {
        perror("Error reopening output file for reading");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), out)) {
        printf("%s", line);
    }

    fclose(out);
    return 0;
}