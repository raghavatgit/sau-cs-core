public class ATMMachine {
    private String accountId;
    private String accountHolder;
    private double balance;
    private StringBuilder history;

    private static String bankName;
    private static int totalAccounts;

    static {
        bankName = "State Bank of India";
        totalAccounts = 0;
        System.out.println("ATM system initialized.");
    }

    public ATMMachine(String accountId, String accountHolder, double initialDeposit) {
        this.accountId = accountId;
        this.accountHolder = accountHolder;
        this.balance = initialDeposit;
        totalAccounts++;
        this.history = new StringBuilder();
        this.history.append("Account opened with balance: Rs.").append(initialDeposit).append("\n");
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
        if (amount <= 0) {
            System.out.println("Amount must be positive.");
            return;
        }
        balance += amount;
        history.append("Deposit: Rs.").append(amount).append(" | Balance: Rs.").append(balance).append("\n");
        System.out.println("Deposited Rs." + amount);
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Amount must be positive.");
            return;
        }
        if (amount > balance) {
            System.out.println("Insufficient balance.");
            return;
        }
        balance -= amount;
        history.append("Withdraw: Rs.").append(amount).append(" | Balance: Rs.").append(balance).append("\n");
        System.out.println("Withdrew Rs." + amount);
    }

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
}
