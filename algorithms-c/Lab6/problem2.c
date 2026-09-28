#include <stdio.h>

int comparisons = 0;
int swaps = 0;
int n;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void printArray(int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int l, int h) {
    int pivot = A[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        comparisons++;
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[h]);
    printf("After partition (l=%d, h=%d): ", l, h);
    printArray(A);
    return i + 1;
}

void quickSort(int A[], int l, int h) {
    if (l < h) {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

int main() {
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++) {
        printf("\n--- Test Case %d ---\n", tc);
        comparisons = 0;
        swaps = 0;

        printf("Enter size of array: ");
        scanf("%d", &n);

        int A[100];
        printf("Enter array elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }

        printf("Original array: ");
        printArray(A);

        quickSort(A, 0, n - 1);

        printf("Sorted array: ");
        printArray(A);

        printf("Total comparisons: %d\n", comparisons);
        printf("Total swaps: %d\n", swaps);
    }

    return 0;
}
