#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main() {

    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter an array A of size N (%d): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Before ROTATE: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("Enter number to rotate right: ");
    int k;
    scanf("%d", &k);

    ROTATE_RIGHT(A, k);

    printf("\nAfter ROTATE: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}