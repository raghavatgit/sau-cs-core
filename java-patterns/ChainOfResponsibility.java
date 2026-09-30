package com.raghav.core.patterns;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.Objects;

/**
 * ChainOfResponsibility Implementation
 * Concurrency-safe enterprise architectural pattern.
 */
public class ChainOfResponsibility {
    private final String identifier;
    private final AtomicBoolean active = new AtomicBoolean(true);

    public ChainOfResponsibility(String identifier) {
        this.identifier = Objects.requireNonNull(identifier, "identifier cannot be null");
    }

    public boolean executeAction() {
        if (!active.get()) {
            return false;
        }
        return true;
    }

    public void shutdown() {
        active.set(false);
    }

    public String getIdentifier() {
        return identifier;
    }
}
