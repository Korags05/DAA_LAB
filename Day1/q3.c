/*
Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
    a) Find out the total number of duplicate elements.
    b) Find out the most repeating element in the array.
*/

#include <stdio.h>

int main() {
    FILE *fp;
    int n;

    fp = fopen("input3.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }   

    fscanf(fp, "%d", &n);
    int arr[n], freq[n];

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
        freq[i] = -1;
    }

    fclose(fp);

    for (int i = 0; i < n; i++) {
        if (freq[i] == -1) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
        }
    }

    int totalDuplicates = 0;
    for (int i = 0; i < n; i++) {
        if (freq[i] > 1) {
            totalDuplicates++;
        }
    }

    int maxFreq = 0, mostRepeating;
    for (int i = 0; i < n; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostRepeating = arr[i];
        }
    }

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTotal number of duplicate values = %d\n", totalDuplicates);
    printf("The most repeating element in the array = %d (repeated %d times)\n", mostRepeating, maxFreq);

    return 0;
}