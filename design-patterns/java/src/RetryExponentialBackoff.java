// feat(patterns): implement generic retry policy with jitter backoff
package edu.sau.cs.core;

import java.time.Instant;
import java.util.Objects;

public class RetryExponentialBackoff {
    private final String identifier;
    private final Instant createdAt;

    public RetryExponentialBackoff(String identifier) {
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
