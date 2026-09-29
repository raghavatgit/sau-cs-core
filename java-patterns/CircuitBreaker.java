package org.sau.patterns;

public class CircuitBreaker {
    public enum State { CLOSED, OPEN, HALF_OPEN }

    private State state = State.CLOSED;
    private int failureCount = 0;
    private final int threshold;
    private long lastStateChange = System.currentTimeMillis();

    public CircuitBreaker(int failureThreshold) {
        this.threshold = failureThreshold;
    }

    public synchronized void recordFailure() {
        failureCount++;
        if (failureCount >= threshold) {
            state = State.OPEN;
            lastStateChange = System.currentTimeMillis();
        }
    }

    public synchronized void recordSuccess() {
        failureCount = 0;
        state = State.CLOSED;
    }

    public synchronized State getState() {
        if (state == State.OPEN && System.currentTimeMillis() - lastStateChange > 5000) {
            state = State.HALF_OPEN;
        }
        return state;
    }
}
