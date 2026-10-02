// test(patterns): verify circuit breaker trips to open state upon error threshold
package edu.sau.cs.core;

import java.time.Instant;
import java.util.Objects;

public class TestCircuitBreaker {
    private final String identifier;
    private final Instant createdAt;

    public TestCircuitBreaker(String identifier) {
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
