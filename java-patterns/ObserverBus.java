package org.sau.patterns;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.function.Consumer;

public class ObserverBus<T> {
    private final List<Consumer<T>> listeners = new CopyOnWriteArrayList<>();

    public void register(Consumer<T> listener) {
        listeners.add(listener);
    }

    public void unregister(Consumer<T> listener) {
        listeners.remove(listener);
    }

    public void publish(T event) {
        for (Consumer<T> listener : listeners) {
            listener.accept(event);
        }
    }
}
