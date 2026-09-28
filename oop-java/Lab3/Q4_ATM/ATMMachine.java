public class ATMMachine {
    private String accountId;
    private String accountHolder;
    private double balance;

    private static String bankName;
    private static int totalAccounts;

    static {
        bankName = "State Bank of India";
        totalAccounts = 0;
        System.out.println("ATM system has been initialized.");
    }

    public ATMMachine(String accountId, String accountHolder, double initialDeposit) {
        this.accountId = accountId;
        this.accountHolder = accountHolder;
        this.balance = initialDeposit;
        totalAccounts++;
    }

    public String getAccountId() {
        return accountId;
    }

    public String getAccountHolder() {
        return accountHolder;
    }

    public double getBalance() {
        return balance;
    }

    public static String getBankName() {
        return bankName;
    }

    public static int getTotalAccounts() {
        return totalAccounts;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Deposit amount must be positive.");
            return;
        }
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Withdrawal amount must be positive.");
            return;
        }
        if (amount > balance) {
            System.out.println("Insufficient balance.");
            return;
        }
        balance -= amount;
    }

    public void displayAccountInfo() {
        System.out.println("Bank: " + bankName);
        System.out.println("Account ID: " + accountId);
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Balance: Rs." + balance);
    }
}
