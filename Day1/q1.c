/*
Write a program to find out the second smallest and second largest
element stored in an array of n integers.
*/

#include <stdio.h>
int main() {

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        int temp;
        for(int j=i+1; j<n ;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    //second smallest is at n-2 index after sorting
    printf("The second smallest element is %d",arr[n-2]); 
    printf("\n");

    //second largest
    printf("The second largest element is %d",arr[1]); 
    return 0;
}