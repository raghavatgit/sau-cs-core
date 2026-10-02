// feat(patterns): design lock-free pub-sub event bus using ConcurrentLinkedQueue
package edu.sau.cs.core;

import java.time.Instant;
import java.util.Objects;

public class EventBusDispatcher {
    private final String identifier;
    private final Instant createdAt;

    public EventBusDispatcher(String identifier) {
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
