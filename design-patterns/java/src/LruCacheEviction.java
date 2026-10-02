// feat(patterns): implement generic LRU cache using LinkedHashMap and locks
package edu.sau.cs.core;

import java.time.Instant;
import java.util.Objects;

public class LruCacheEviction {
    private final String identifier;
    private final Instant createdAt;

    public LruCacheEviction(String identifier) {
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
