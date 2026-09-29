package enterprise;

import java.util.HashMap;
import java.util.Map;

public class CQRSCommandQueryDispatcher {
    private final Map<Class<?>, Object> commandHandlers = new HashMap<>();
    private final Map<Class<?>, Object> queryHandlers = new HashMap<>();
}
