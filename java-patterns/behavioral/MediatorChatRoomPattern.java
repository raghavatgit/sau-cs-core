package behavioral;

interface ChatMediator { void sendMessage(String msg, User user); }

abstract class User {
    protected ChatMediator mediator;
    protected String name;
    public User(ChatMediator m, String n) { this.mediator = m; this.name = n; }
    public abstract void send(String msg);
    public abstract void receive(String msg);
}
