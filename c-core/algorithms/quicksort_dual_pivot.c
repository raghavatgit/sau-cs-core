#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void dual_pivot_quicksort(int *arr, int low, int high) {
    if (low >= high) return;

    if (arr[low] > arr[high]) swap(&arr[low], &arr[high]);

    int p = arr[low];
    int q = arr[high];
    int l = low + 1;
    int g = high - 1;
    int k = l;

    while (k <= g) {
        if (arr[k] < p) {
            swap(&arr[k], &arr[l]);
            l++;
        } else if (arr[k] >= q) {
            while (arr[g] > q && k < g) g--;
            swap(&arr[k], &arr[g]);
            g--;
            if (arr[k] < p) {
                swap(&arr[k], &arr[l]);
                l++;
            }
        }
        k++;
    }
    l--;
    g++;
    swap(&arr[low], &arr[l]);
    swap(&arr[high], &arr[g]);

    dual_pivot_quicksort(arr, low, l - 1);
    dual_pivot_quicksort(arr, l + 1, g - 1);
    dual_pivot_quicksort(arr, g + 1, high);
}
