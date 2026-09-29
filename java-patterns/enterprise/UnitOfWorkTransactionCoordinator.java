package enterprise;

import java.util.ArrayList;
import java.util.List;

public class UnitOfWorkTransactionCoordinator<T> {
    private final List<T> newEntities = new ArrayList<>();
    private final List<T> dirtyEntities = new ArrayList<>();
    private final List<T> removedEntities = new ArrayList<>();

    public void registerNew(T entity) { newEntities.add(entity); }
    public void registerDirty(T entity) { dirtyEntities.add(entity); }
    public void registerRemoved(T entity) { removedEntities.add(entity); }
}
