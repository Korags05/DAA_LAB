/*
Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i]. 
*/

#include <stdio.h>

int main() {
    FILE *fp;
    int n;

    fp = fopen("input2.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    int arr[n], prefixSum[n];

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }

    return 0;
}