/*
Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
    a) Find out the total number of duplicate elements.
    b) Find out the most repeating element in the array.
*/

#include <stdio.h>
int main() {

    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n], freq[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;  
    }

    for (int i = 0; i < n; i++) {
        if (freq[i] == -1) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;  // Mark as counted
                }
            }
            freq[i] = count;
        }
    }

    // (a) Count total number of duplicate elements
    int totalDuplicates = 0;
    for (int i = 0; i < n; i++) {
        if (freq[i] > 1) {
            totalDuplicates++;
        }
    }

    // (b) Find most repeating element
    int maxFreq = 0, mostRepeating;
    for (int i = 0; i < n; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostRepeating = arr[i];
        }
    }

    // Output
    printf("\nTotal number of duplicate elements: %d\n", totalDuplicates);
    printf("Most repeating element: %d (repeated %d times)\n", mostRepeating, maxFreq);

    return 0;
}