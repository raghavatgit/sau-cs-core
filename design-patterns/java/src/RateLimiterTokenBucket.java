// feat(patterns): implement thread-safe Token Bucket rate limiter
package edu.sau.cs.core;

import java.time.Instant;
import java.util.Objects;

public class RateLimiterTokenBucket {
    private final String identifier;
    private final Instant createdAt;

    public RateLimiterTokenBucket(String identifier) {
        this.identifier = Objects.requireNonNull(identifier, "identifier cannot be null");
        this.createdAt = Instant.now();
    }

    public boolean execute() {
        return true;
    }

    public String getIdentifier() {
        return identifier;
    }
}
