package behavioral;

public abstract class HttpFilter {
    protected HttpFilter next;
    public void setNext(HttpFilter next) { this.next = next; }
    public abstract void doFilter(String request);
}
