package bank.main;

import bank.model.Account;
import bank.model.SavingsAccount;
import bank.model.CurrentAccount;
import java.util.Scanner;

public class ATMApp {

    private static Account findAccount(Account[] accounts, String accountId) {
        for (int i = 0; i < accounts.length; i++) {
            if (accounts[i] != null && accounts[i].getAccountId().equals(accountId)) {
                return accounts[i];
            }
        }
        return null;
    }

    private static void searchByName(Account[] accounts, String query) {
        String clean = query.trim().toLowerCase();
        System.out.println("\nMatching accounts:");
        boolean found = false;
        for (int i = 0; i < accounts.length; i++) {
            if (accounts[i] != null && accounts[i].getAccountHolder().toLowerCase().contains(clean)) {
                System.out.println(accounts[i].getMaskedAccountId() + " - " + accounts[i].getAccountHolder() + 
                                   " (" + accounts[i].getClass().getSimpleName() + "): Rs." + accounts[i].getBalance());
                found = true;
            }
        }
        if (!found) {
            System.out.println("No accounts found matching " + query);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Account[] accounts = new Account[4];
        accounts[0] = new SavingsAccount("10003314", "Rahul Sharma", 5000.0, 1000.0, 4.0);
        accounts[1] = new CurrentAccount("10005521", "Priya Singh", 8000.0, 5000.0);
        accounts[2] = new SavingsAccount("10007789", "Amit Verma", 2500.0, 1000.0, 3.5);
        accounts[3] = new CurrentAccount("10009943", "Sneha Gupta", 12000.0, 8000.0);

        System.out.println("Bank: " + Account.getBankName());
        System.out.println("Total Accounts: " + Account.getTotalAccounts());

        boolean running = true;

        while (running) {
            System.out.println("\nMain Menu:");
            System.out.println("1. Login by Account ID");
            System.out.println("2. Search by Name");
            System.out.println("3. Display All Accounts");
            System.out.println("4. Exit");
            System.out.print("Select choice: ");

            int mainChoice = sc.nextInt();
            sc.nextLine();

            if (mainChoice == 2) {
                System.out.print("Enter name to search: ");
                String name = sc.nextLine();
                searchByName(accounts, name);
                continue;
            } else if (mainChoice == 3) {
                System.out.println("\nAll Accounts:");
                for (int i = 0; i < accounts.length; i++) {
                    System.out.print((i + 1) + ". ");
                    accounts[i].displayAccountInfo();
                    System.out.println();
                }
                continue;
            } else if (mainChoice == 4) {
                System.out.println("Exiting system.");
                break;
            } else if (mainChoice != 1) {
                System.out.println("Invalid choice.");
                continue;
            }

            System.out.print("Enter Account ID: ");
            String accId = sc.nextLine().trim();

            Account current = findAccount(accounts, accId);
            if (current == null) {
                System.out.println("Account not found.");
                continue;
            }

            current.displayAccountInfo();

            boolean inAccount = true;
            while (inAccount) {
                System.out.println("\nOperations for " + current.getMaskedAccountId() + ":");
                System.out.println("1. Deposit (Cash)");
                System.out.println("2. Deposit with Mode (Cheque/Online)");
                System.out.println("3. Withdraw");
                System.out.println("4. Check Balance");
                System.out.println("5. View History");
                System.out.println("6. Search History");
                System.out.println("7. Transfer Money");
                System.out.println("8. Calculate Interest");
                System.out.println("9. Switch Account");
                System.out.println("10. Exit");
                System.out.print("Select option: ");

                int op = sc.nextInt();
                sc.nextLine();

                switch (op) {
                    case 1:
                        System.out.print("Enter deposit amount: ");
                        double amt1 = sc.nextDouble();
                        sc.nextLine();
                        current.deposit(amt1);
                        break;
                    case 2:
                        System.out.print("Enter deposit amount: ");
                        double amt2 = sc.nextDouble();
                        sc.nextLine();
                        System.out.print("Enter mode (Cheque/Online): ");
                        String mode = sc.nextLine();
                        current.deposit(amt2, mode);
                        break;
                    case 3:
                        System.out.print("Enter withdrawal amount: ");
                        double w = sc.nextDouble();
                        sc.nextLine();
                        current.withdraw(w);
                        break;
                    case 4:
                        System.out.println("Balance: Rs." + current.getBalance());
                        break;
                    case 5:
                        current.displayHistory();
                        break;
                    case 6:
                        System.out.print("Enter type keyword (Deposit/Withdraw/Transfer): ");
                        String tType = sc.nextLine();
                        current.searchHistory(tType);
                        break;
                    case 7:
                        System.out.print("Enter destination Account ID: ");
                        String destId = sc.nextLine().trim();
                        Account destAcc = findAccount(accounts, destId);
                        if (destAcc == null) {
                            System.out.println("Destination account not found.");
                            break;
                        }
                        System.out.print("Enter amount to transfer: ");
                        double tAmt = sc.nextDouble();
                        sc.nextLine();
                        current.transferTo(destAcc, tAmt);
                        break;
                    case 8:
                        if (current instanceof SavingsAccount) {
                            ((SavingsAccount) current).calculateAndDisplayInterest();
                        } else {
                            System.out.println("Interest is only applicable to Savings Accounts.");
                        }
                        break;
                    case 9:
                        inAccount = false;
                        break;
                    case 10:
                        inAccount = false;
                        running = false;
                        break;
                    default:
                        System.out.println("Invalid option.");
                }
            }
        }

        sc.close();
    }
}
