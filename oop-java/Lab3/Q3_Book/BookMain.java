import java.util.Scanner;

public class BookMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Book[] books = new Book[8];
        for (int i = 0; i < books.length; i++) {
            books[i] = null;
        }

        books[0] = new Book("To Kill a Mockingbird", "Harper Lee", "978-0061120084", 450.0, "Fiction");
        books[1] = new Book("Wings of Fire", "A.P.J. Abdul Kalam", "978-8173711466", 299.0, "Autobiography");
        books[2] = new Book("1984", "George Orwell", "978-0451524935", 350.0, "Fiction");
        books[3] = new Book("Animal Farm", "George Orwell", "978-0451526342", 220.0, "Fiction");
        books[4] = new Book("The Story of My Experiments with Truth", "Mahatma Gandhi", "978-8172290085", 199.0, "Autobiography");
        books[5] = new Book("Ignited Minds", "A.P.J. Abdul Kalam", "978-0143424123", 250.0, "Inspirational");
        books[6] = new Book("The Alchemist", "Paulo Coelho", "978-0062315007", 320.0, "Fiction");
        books[7] = new Book("Clean Code", "Robert C. Martin", "978-0132350884", 850.0, "Technology");

        System.out.println("Available Books:");
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                System.out.print((i + 1) + ". ");
                books[i].displayBook();
            }
        }
        System.out.println();

        System.out.print("Enter author name to search: ");
        String searchAuthor = sc.nextLine().trim();
        System.out.println("Books by " + searchAuthor + ":");
        boolean foundAuthor = false;
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null && books[i].getAuthor().equalsIgnoreCase(searchAuthor)) {
                System.out.println(books[i].getTitle() + " (Rs. " + books[i].getPrice() + ")");
                foundAuthor = true;
            }
        }
        if (!foundAuthor) {
            System.out.println("No books found for this author.");
        }
        System.out.println();

        System.out.print("Enter category to search: ");
        String searchCategory = sc.nextLine().trim();
        System.out.println("Books in category " + searchCategory + ":");
        boolean foundCategory = false;
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null && books[i].getCategory().equalsIgnoreCase(searchCategory)) {
                System.out.println(books[i].getTitle() + " by " + books[i].getAuthor());
                foundCategory = true;
            }
        }
        if (!foundCategory) {
            System.out.println("No books found in this category.");
        }
        System.out.println();

        System.out.print("Enter max price: ");
        double maxPrice = sc.nextDouble();
        System.out.println("Books with price <= " + maxPrice + ":");
        boolean foundPrice = false;
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null && books[i].getPrice() <= maxPrice) {
                System.out.println(books[i].getTitle() + " - Rs. " + books[i].getPrice());
                foundPrice = true;
            }
        }
        if (!foundPrice) {
            System.out.println("No books found under this price.");
        }

        sc.close();
    }
}
