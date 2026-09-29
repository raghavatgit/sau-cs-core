package org.sau.core;

import java.util.SortedMap;
import java.util.TreeMap;

public class ConsistentHashRing<T> {
    private final SortedMap<Integer, T> circle = new TreeMap<>();
    private final int numberOfReplicas;

    public ConsistentHashRing(int numberOfReplicas) {
        this.numberOfReplicas = numberOfReplicas;
    }

    public void addNode(T node) {
        for (int i = 0; i < numberOfReplicas; i++) {
            circle.put((node.toString() + i).hashCode(), node);
        }
    }

    public T getNode(Object key) {
        if (circle.isEmpty()) return null;
        int hash = key.hashCode();
        if (!circle.containsKey(hash)) {
            SortedMap<Integer, T> tail = circle.tailMap(hash);
            hash = tail.isEmpty() ? circle.firstKey() : tail.firstKey();
        }
        return circle.get(hash);
    }
}
