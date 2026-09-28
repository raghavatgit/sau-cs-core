package behavioral;

interface PaymentStrategy { void pay(int amount); }

public class CreditCardStrategy implements PaymentStrategy {
    public void pay(int amount) { System.out.println("Paid " + amount + " via Card"); }
}
