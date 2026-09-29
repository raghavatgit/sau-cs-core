package enterprise;

import java.util.ArrayList;
import java.util.List;

public abstract class EventSourcingAggregateRoot<E> {
    private final List<E> uncommittedEvents = new ArrayList<>();

    protected void applyChange(E event) {
        mutate(event);
        uncommittedEvents.add(event);
    }

    protected abstract void mutate(E event);
}
