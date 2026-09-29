package org.sau.core;

import java.util.concurrent.RecursiveAction;

public class ParallelMergeSort extends RecursiveAction {
    private final int[] array;
    private final int left, right;

    public ParallelMergeSort(int[] array, int left, int right) {
        this.array = array; this.left = left; this.right = right;
    }

    protected void compute() {
        if (right - left < 1000) {
            java.util.Arrays.sort(array, left, right + 1);
            return;
        }
        int mid = (left + right) / 2;
        invokeAll(new ParallelMergeSort(array, left, mid), new ParallelMergeSort(array, mid + 1, right));
    }
}
