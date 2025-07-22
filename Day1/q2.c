/*
Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i]. 
*/

#include <stdio.h>
int main() {
    int n;

    //take size of array
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n], prefixSum[n];

    //take input of array
    for (int i = 0; i<n; i++) {
        printf("Enter the element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    //calculate prefix sum
    //prefixSum[i] will store the sum of elements from arr[0] to arr[i]
    prefixSum[0] = arr[0];
    for (int i = 1; i<n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    // Print the prefix sum array
    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }

    return 0;
}