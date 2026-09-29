package concurrency;

import java.util.concurrent.atomic.LongAdder;

public class StripedLong64Adder {
    private final LongAdder counter = new LongAdder();

    public void increment() {
        counter.increment();
    }

    public long sum() {
        return counter.sum();
    }
}
