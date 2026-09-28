package behavioral;

interface OrderState { void next(OrderContext ctx); }

class PendingState implements OrderState {
    public void next(OrderContext ctx) { System.out.println("Transitioned to Shipped"); }
}

public class OrderContext {
    private OrderState state = new PendingState();
    public void next() { state.next(this); }
}
