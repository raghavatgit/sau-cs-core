package org.sau.core;

public class RateLimiterTokenBucket {
    private final long capacity;
    private final double refillRatePerSec;
    private double tokens;
    private long lastRefillTimestamp;

    public RateLimiterTokenBucket(long capacity, double refillRatePerSec) {
        this.capacity = capacity;
        this.refillRatePerSec = refillRatePerSec;
        this.tokens = capacity;
        this.lastRefillTimestamp = System.nanoTime();
    }

    public synchronized boolean tryConsume() {
        long now = System.nanoTime();
        double elapsedSec = (now - lastRefillTimestamp) / 1e9;
        tokens = Math.min(capacity, tokens + elapsedSec * refillRatePerSec);
        lastRefillTimestamp = now;

        if (tokens >= 1.0) {
            tokens -= 1.0;
            return true;
        }
        return false;
    }
}
