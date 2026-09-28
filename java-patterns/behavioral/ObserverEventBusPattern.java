package behavioral;

import java.util.ArrayList;
import java.util.List;

interface EventListener { void onEvent(String event); }

public class EventPublisher {
    private final List<EventListener> listeners = new ArrayList<>();
    public void subscribe(EventListener l) { listeners.add(l); }
    public void publish(String event) {
        for (EventListener l : listeners) l.onEvent(event);
    }
}
