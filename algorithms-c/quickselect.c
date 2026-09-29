/*
 * Quickselect algorithm to find kth smallest element in O(n) average time
 */
#include <stdio.h>

static void swap(int* a, int* b) {
    int tmp = *a; *a = *b; *b = tmp;
}

static int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

int quickselect(int arr[], int left, int right, int k) {
    if (left == right) return arr[left];
    int p = partition(arr, left, right);
    if (k == p) return arr[k];
    else if (k < p) return quickselect(arr, left, p - 1, k);
    else return quickselect(arr, p + 1, right, k);
}
