import java.util.Scanner;

public class ATMMain {
    private static ATMMachine findAccount(ATMMachine[] accounts, String accountId) {
        for (int i = 0; i < accounts.length; i++) {
            if (accounts[i] != null && accounts[i].getAccountId().equals(accountId)) {
                return accounts[i];
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ATMMachine[] accounts = new ATMMachine[5];
        accounts[0] = new ATMMachine("12345", "Rahul Sharma", 1000.0);
        accounts[1] = new ATMMachine("23456", "Priya Singh", 1000.0);
        accounts[2] = new ATMMachine("34567", "Amit Verma", 1000.0);
        accounts[3] = new ATMMachine("45678", "Sneha Gupta", 1000.0);
        accounts[4] = new ATMMachine("56789", "Vikas Kumar", 1000.0);

        System.out.println("Total Accounts: " + ATMMachine.getTotalAccounts());
        System.out.println("Bank: " + ATMMachine.getBankName());

        boolean running = true;

        while (running) {
            System.out.print("\nEnter Account id: ");
            String id = sc.nextLine().trim();

            ATMMachine acc = findAccount(accounts, id);
            if (acc == null) {
                System.out.println("Account not found.");
                continue;
            }

            boolean inAccount = true;
            while (inAccount) {
                System.out.println("\nMenu:");
                System.out.println("1. Deposit");
                System.out.println("2. Withdraw");
                System.out.println("3. Check Balance");
                System.out.println("4. Enter another account");
                System.out.println("5. Exit");
                System.out.print("Select Option number: ");

                int choice = sc.nextInt();
                sc.nextLine();

                switch (choice) {
                    case 1:
                        System.out.print("Enter Amount to deposit: ");
                        double dep = sc.nextDouble();
                        sc.nextLine();
                        acc.deposit(dep);
                        break;
                    case 2:
                        System.out.print("Enter Amount to withdraw: ");
                        double w = sc.nextDouble();
                        sc.nextLine();
                        acc.withdraw(w);
                        break;
                    case 3:
                        System.out.println("Balance: Rs." + acc.getBalance());
                        break;
                    case 4:
                        inAccount = false;
                        break;
                    case 5:
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
