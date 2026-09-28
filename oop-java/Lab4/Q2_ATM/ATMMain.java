import java.util.Scanner;

public class ATMMain {
    private static ATMMachine findAccountById(ATMMachine[] accounts, String id) {
        for (int i = 0; i < accounts.length; i++) {
            if (accounts[i] != null && accounts[i].getAccountId().equals(id)) {
                return accounts[i];
            }
        }
        return null;
    }

    private static void searchAccountsByName(ATMMachine[] accounts, String searchName) {
        String query = searchName.trim().toLowerCase();
        System.out.println("\nMatching Accounts:");
        boolean found = false;
        for (int i = 0; i < accounts.length; i++) {
            if (accounts[i] != null) {
                String h = accounts[i].getAccountHolder().toLowerCase();
                if (h.contains(query)) {
                    System.out.println("ID: " + accounts[i].getAccountId() + 
                                       " | Masked: " + accounts[i].getMaskedAccountId() + 
                                       " | Name: " + accounts[i].getAccountHolder() + 
                                       " | Balance: Rs." + accounts[i].getBalance());
                    found = true;
                }
            }
        }
        if (!found) {
            System.out.println("No accounts found with name: " + searchName);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ATMMachine[] accounts = new ATMMachine[5];
        accounts[0] = new ATMMachine("10003314", "Rahul Sharma", 1000.0);
        accounts[1] = new ATMMachine("10005521", "Priya Singh", 1000.0);
        accounts[2] = new ATMMachine("10007789", "Amit Sharma", 1000.0);
        accounts[3] = new ATMMachine("10009943", "Sneha Verma", 1000.0);
        accounts[4] = new ATMMachine("10001122", "Vikas Patel", 1000.0);

        boolean running = true;

        while (running) {
            System.out.println("\nMain Menu:");
            System.out.println("1. Login by Account ID");
            System.out.println("2. Search Account by Holder Name");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");

            int mainChoice = sc.nextInt();
            sc.nextLine();

            if (mainChoice == 2) {
                System.out.print("Enter name to search: ");
                String nameQuery = sc.nextLine();
                searchAccountsByName(accounts, nameQuery);
                continue;
            } else if (mainChoice == 3) {
                System.out.println("Exiting ATM.");
                break;
            } else if (mainChoice != 1) {
                System.out.println("Invalid choice.");
                continue;
            }

            System.out.print("Enter Account id: ");
            String id = sc.nextLine().trim();

            ATMMachine acc = findAccountById(accounts, id);
            if (acc == null) {
                System.out.println("Account not found.");
                continue;
            }

            acc.displayAccountInfo();

            boolean inAccount = true;
            while (inAccount) {
                System.out.println("\nAccount Menu (" + acc.getMaskedAccountId() + "):");
                System.out.println("1. Deposit");
                System.out.println("2. Withdraw");
                System.out.println("3. Check Balance");
                System.out.println("4. View History");
                System.out.println("5. Search History by Type");
                System.out.println("6. Switch Account");
                System.out.println("7. Exit");
                System.out.print("Enter option: ");

                int opt = sc.nextInt();
                sc.nextLine();

                switch (opt) {
                    case 1:
                        System.out.print("Enter deposit amount: ");
                        double dep = sc.nextDouble();
                        sc.nextLine();
                        acc.deposit(dep);
                        break;
                    case 2:
                        System.out.print("Enter withdrawal amount: ");
                        double w = sc.nextDouble();
                        sc.nextLine();
                        acc.withdraw(w);
                        break;
                    case 3:
                        System.out.println("Balance: Rs." + acc.getBalance());
                        break;
                    case 4:
                        acc.displayHistory();
                        break;
                    case 5:
                        System.out.print("Enter type (Deposit/Withdraw): ");
                        String type = sc.nextLine();
                        acc.searchHistory(type);
                        break;
                    case 6:
                        inAccount = false;
                        break;
                    case 7:
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
