package bank.model;

public class CurrentAccount extends Account {
    private double overdraftLimit;

    public CurrentAccount(String accountId, String accountHolder, double initialDeposit, double overdraftLimit) {
        super(accountId, accountHolder, initialDeposit);
        this.overdraftLimit = overdraftLimit;
    }

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    public void setOverdraftLimit(double overdraftLimit) {
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public boolean withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Amount must be positive.");
            return false;
        }

        double totalLimit = balance + overdraftLimit;

        if (amount > totalLimit) {
            System.out.println("Withdrawal denied: Exceeds overdraft limit.");
            return false;
        }

        balance -= amount;
        history.append("Withdraw: Rs.").append(amount).append(" | Balance: Rs.").append(balance);
        if (balance < 0) {
            history.append(" (Overdraft used: Rs.").append(-balance).append(")");
        }
        history.append("\n");

        System.out.println("Withdrew Rs." + amount);
        if (balance < 0) {
            System.out.println("Current balance is negative: Rs." + balance);
        }
        return true;
    }

    @Override
    public void displayAccountInfo() {
        System.out.println("[Current Account]");
        super.displayAccountInfo();
        System.out.println("Overdraft Limit: Rs." + overdraftLimit);
        System.out.println("Total Available with Overdraft: Rs." + (balance + overdraftLimit));
    }
}
