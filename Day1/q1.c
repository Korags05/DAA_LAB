/*
Write a program to find out the second smallest and second largest
element stored in an array of n integers.
*/

#include <stdio.h>

int main() {
    FILE *fp;
    int n;

    fp = fopen("input1.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp); // close the file

    // bubble sort to sort the array in descending order
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The second smallest element is %d\n", arr[n - 2]);
    printf("The second largest element is %d\n", arr[1]);

    return 0;
}