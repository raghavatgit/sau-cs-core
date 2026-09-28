package bank.model;

public abstract class Account {
    protected String accountId;
    protected String accountHolder;
    protected double balance;
    protected StringBuilder history;

    protected static String bankName;
    protected static int totalAccounts;

    static {
        bankName = "State Bank of India";
        totalAccounts = 0;
        System.out.println("ATM system initialized.");
    }

    public Account(String accountId, String accountHolder, double initialDeposit) {
        this.accountId = accountId;
        this.accountHolder = accountHolder;
        this.balance = initialDeposit;
        this.history = new StringBuilder();
        this.history.append("Account created with balance: Rs.").append(initialDeposit).append("\n");
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

    public String getMaskedAccountId() {
        if (accountId == null || accountId.length() <= 4) {
            return accountId;
        }
        int maskCount = accountId.length() - 4;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < maskCount; i++) {
            sb.append('*');
        }
        sb.append(accountId.substring(maskCount));
        return sb.toString();
    }

    public void deposit(double amount) {
        deposit(amount, "Cash");
    }

    public void deposit(double amount, String mode) {
        if (amount <= 0) {
            System.out.println("Amount must be positive.");
            return;
        }
        balance += amount;
        history.append("Deposit (").append(mode).append("): Rs.").append(amount)
               .append(" | Balance: Rs.").append(balance).append("\n");
        System.out.println("Deposited Rs." + amount + " via " + mode);
    }

    public abstract boolean withdraw(double amount);

    public void displayAccountInfo() {
        System.out.println("Bank: " + bankName);
        System.out.println("Account Number: " + getMaskedAccountId());
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Balance: Rs." + balance);
    }

    public void displayHistory() {
        System.out.println("\nTransaction History for " + getMaskedAccountId() + ":");
        System.out.print(history.toString());
    }

    public void searchHistory(String type) {
        System.out.println("\nMatching Transactions (" + type + "):");
        String[] lines = history.toString().split("\n");
        boolean found = false;
        for (int i = 0; i < lines.length; i++) {
            if (lines[i].toLowerCase().contains(type.toLowerCase().trim())) {
                System.out.println(lines[i]);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No matching transactions found.");
        }
    }

    public boolean transferTo(Account destination, double amount) {
        if (destination == null) {
            System.out.println("Destination account not found.");
            return false;
        }
        if (destination.getAccountId().equals(this.accountId)) {
            System.out.println("Cannot transfer to the same account.");
            return false;
        }

        if (this.withdraw(amount)) {
            destination.deposit(amount, "Transfer from " + this.getMaskedAccountId());
            this.history.append("Transfer Out: Rs.").append(amount)
                .append(" to ").append(destination.getMaskedAccountId()).append("\n");
            destination.history.append("Transfer In: Rs.").append(amount)
                .append(" from ").append(this.getMaskedAccountId()).append("\n");
            System.out.println("Transfer of Rs." + amount + " successful.");
            return true;
        } else {
            System.out.println("Transfer failed.");
            return false;
        }
    }
}
