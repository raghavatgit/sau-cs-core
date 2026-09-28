package concurrency;

import java.util.concurrent.RecursiveTask;

public class ParallelArraySum extends RecursiveTask<Long> {
    private static final int THRESHOLD = 1000;
    private final long[] array;
    private final int start, end;

    public ParallelArraySum(long[] array, int start, int end) {
        this.array = array;
        this.start = start;
        this.end = end;
    }

    protected Long compute() {
        if (end - start <= THRESHOLD) {
            long sum = 0;
            for (int i = start; i < end; i++) sum += array[i];
            return sum;
        } else {
            int mid = (start + end) / 2;
            ParallelArraySum left = new ParallelArraySum(array, start, mid);
            ParallelArraySum right = new ParallelArraySum(array, mid, end);
            left.fork();
            return right.compute() + left.join();
        }
    }
}
