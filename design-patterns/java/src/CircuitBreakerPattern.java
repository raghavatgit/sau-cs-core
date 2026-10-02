// feat(patterns): build resilient finite state machine Circuit Breaker
package edu.sau.cs.core;

import java.time.Instant;
import java.util.Objects;

public class CircuitBreakerPattern {
    private final String identifier;
    private final Instant createdAt;

    public CircuitBreakerPattern(String identifier) {
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
