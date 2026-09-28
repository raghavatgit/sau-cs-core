package structural;

import java.util.HashMap;
import java.util.Map;

interface HeavyService { String fetchData(String id); }

public class CachingProxy implements HeavyService {
    private final HeavyService realService;
    private final Map<String, String> cache = new HashMap<>();

    public CachingProxy(HeavyService s) { this.realService = s; }

    public String fetchData(String id) {
        if (!cache.containsKey(id)) {
            cache.put(id, realService.fetchData(id));
        }
        return cache.get(id);
    }
}
