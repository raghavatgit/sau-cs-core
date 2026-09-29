package enterprise;

public class OutboxTransactionalPublisher {
    public void publishEvent(String aggregateType, String payload) {
        // Enqueue into outbox table in same ACID transaction
    }
}
