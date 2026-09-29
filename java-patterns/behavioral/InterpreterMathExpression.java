package behavioral;

interface Expression { int interpret(); }

class NumberExpression implements Expression {
    private final int value;
    public NumberExpression(int v) { this.value = v; }
    public int interpret() { return value; }
}
