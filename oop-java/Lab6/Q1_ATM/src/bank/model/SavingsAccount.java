package bank.model;

public class SavingsAccount extends Account {
    private double minimumBalance;
    private double interestRate;

    public SavingsAccount(String accountId, String accountHolder, double initialDeposit, 
                          double minimumBalance, double interestRate) {
        super(accountId, accountHolder, initialDeposit);
        this.minimumBalance = minimumBalance;
        this.interestRate = interestRate;
    }

    public double getMinimumBalance() {
        return minimumBalance;
    }

    public double getInterestRate() {
        return interestRate;
    }

    @Override
    public boolean withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Amount must be positive.");
            return false;
        }

        if (balance - amount < minimumBalance) {
            System.out.println("Withdrawal denied: Minimum balance of Rs." + minimumBalance + " must be maintained.");
            return false;
        }

        balance -= amount;
        history.append("Withdraw: Rs.").append(amount).append(" | Balance: Rs.").append(balance).append("\n");
        System.out.println("Withdrew Rs." + amount);
        return true;
    }

    public void calculateAndDisplayInterest() {
        double interest = balance * (interestRate / 100.0);
        System.out.println("Interest on current balance (" + interestRate + "%): Rs." + interest);
    }

    @Override
    public void displayAccountInfo() {
        System.out.println("[Savings Account]");
        super.displayAccountInfo();
        System.out.println("Minimum Balance: Rs." + minimumBalance);
        System.out.println("Interest Rate: " + interestRate + "%");
    }
}
