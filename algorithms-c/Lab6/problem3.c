#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partitionLomuto(int A[], int l, int h, int *comp, int *swp) {
    int pivot = A[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        (*comp)++;
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
            (*swp)++;
        }
    }
    swap(&A[i + 1], &A[h]);
    (*swp)++;
    return i + 1;
}

void partition3Way(int A[], int l, int h, int *p, int *q, int *comp, int *swp) {
    int pivot = A[h];
    int mid = l;
    *p = l;
    *q = h;
    while (mid <= *q) {
        (*comp)++;
        if (A[mid] < pivot) {
            swap(&A[*p], &A[mid]);
            (*swp)++;
            (*p)++;
            mid++;
        } else {
            (*comp)++;
            if (A[mid] > pivot) {
                swap(&A[mid], &A[*q]);
                (*swp)++;
                (*q)--;
            } else {
                mid++;
            }
        }
    }
}

void quickSortLomuto(int A[], int l, int h, int *comp, int *swp) {
    if (l < h) {
        int p = partitionLomuto(A, l, h, comp, swp);
        quickSortLomuto(A, l, p - 1, comp, swp);
        quickSortLomuto(A, p + 1, h, comp, swp);
    }
}

void quickSort3Way(int A[], int l, int h, int *comp, int *swp) {
    if (l < h) {
        int p, q;
        partition3Way(A, l, h, &p, &q, comp, swp);
        quickSort3Way(A, l, p - 1, comp, swp);
        quickSort3Way(A, q + 1, h, comp, swp);
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int A[100], B[100], C[100], D[100];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
    }

    int compL = 0, swpL = 0;
    int pL = partitionLomuto(A, 0, n - 1, &compL, &swpL);

    int comp3 = 0, swp3 = 0;
    int p3, q3;
    partition3Way(B, 0, n - 1, &p3, &q3, &comp3, &swp3);

    printf("\n--- Single Partition Comparison ---\n");
    printf("Lomuto Partition Result: ");
    printArray(A, n);
    printf("Lomuto Pivot Index: %d, Comparisons: %d, Swaps: %d\n", pL, compL, swpL);

    printf("3-Way Partition Result: ");
    printArray(B, n);
    printf("3-Way Pivot Region: [%d ... %d], Comparisons: %d, Swaps: %d\n", p3, q3, comp3, swp3);

    int sortCompL = 0, sortSwpL = 0;
    quickSortLomuto(C, 0, n - 1, &sortCompL, &sortSwpL);

    int sortComp3 = 0, sortSwp3 = 0;
    quickSort3Way(D, 0, n - 1, &sortComp3, &sortSwp3);

    printf("\n--- Full QuickSort Comparison ---\n");
    printf("Lomuto QuickSort Sorted: ");
    printArray(C, n);
    printf("Lomuto QuickSort -> Total Comparisons: %d, Total Swaps: %d\n", sortCompL, sortSwpL);

    printf("3-Way QuickSort Sorted: ");
    printArray(D, n);
    printf("3-Way QuickSort   -> Total Comparisons: %d, Total Swaps: %d\n", sortComp3, sortSwp3);

    return 0;
}
