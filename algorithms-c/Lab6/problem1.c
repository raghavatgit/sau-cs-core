#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[h]);
    return i + 1;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int A[100];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Before partition: ");
    printArray(A, n);

    int p = partition(A, 0, n - 1);

    printf("After partition: ");
    printArray(A, n);

    printf("Pivot index: %d\n", p);
    printf("Pivot value: %d\n", A[p]);

    return 0;
}
