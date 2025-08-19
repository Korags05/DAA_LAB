#include <stdio.h>
#include <stdlib.h>

// Recursive function to find GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    int num1, num2, result;
    int pairCount = 0;
    
    // Check if correct number of command line arguments are provided
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    
    // Open input file for reading
    inputFile = fopen(argv, "r");  // MUST be argv, not argv
    if (inputFile == NULL) {
        printf("Error: Cannot open input file %s\n", argv);  // MUST be argv
        return 1;
    }
    
    // Open output file for writing
    outputFile = fopen(argv, "w");  // MUST be argv, not argv
    if (outputFile == NULL) {
        printf("Error: Cannot create output file %s\n", argv);  // MUST be argv
        fclose(inputFile);
        return 1;
    }
    
    // Read pairs of numbers from input file and calculate GCD
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        result = gcd(num1, num2);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, result);
        pairCount++;
    }
    
    // Close files
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Processed %d pairs of numbers.\n", pairCount);
    printf("Results have been written to %s\n", argv);
    
    // Display the contents of output file
    printf("\nContents of %s:\n", argv);  // MUST be argv
    outputFile = fopen(argv, "r");  // MUST be argv
    if (outputFile != NULL) {
        char line;  // MUST be char array, not single char
        while (fgets(line, sizeof(line), outputFile) != NULL) {
            printf("%s", line);
        }
        fclose(outputFile);
    }
    
    return 0;
}