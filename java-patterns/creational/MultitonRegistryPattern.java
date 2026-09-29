package creational;

import java.util.concurrent.ConcurrentHashMap;

public class MultitonRegistry {
    private static final ConcurrentHashMap<String, MultitonRegistry> instances = new ConcurrentHashMap<>();
    private final String key;

    private MultitonRegistry(String key) { this.key = key; }

    public static MultitonRegistry getInstance(String key) {
        return instances.computeIfAbsent(key, MultitonRegistry::new);
    }
}
