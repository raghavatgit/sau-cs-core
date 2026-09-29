package concurrency;

public class DisruptorRingBuffer<T> {
    private final Object[] ring;
    private final int mask;
    private volatile long sequence = 0;

    public DisruptorRingBuffer(int bufferSize) {
        this.ring = new Object[bufferSize];
        this.mask = bufferSize - 1;
    }
}
