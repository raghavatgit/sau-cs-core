package booksystem.main;

import booksystem.model.Book;
import booksystem.model.PrintedBook;
import booksystem.model.EBook;
import java.util.Scanner;

public class BookApp {

    public static void searchBook(Book[] books, String keyword) {
        System.out.println("\nSearch results for keyword: " + keyword);
        String kw = keyword.trim().toLowerCase();
        boolean found = false;

        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                if (books[i].getTitle().toLowerCase().contains(kw) || 
                    books[i].getAuthor().toLowerCase().contains(kw)) {
                    books[i].displayBookInfo();
                    found = true;
                }
            }
        }
        if (!found) {
            System.out.println("No matching books found.");
        }
    }

    public static void searchBook(Book[] books, double maxPrice) {
        System.out.println("\nSearch results for price <= Rs." + maxPrice);
        boolean found = false;

        for (int i = 0; i < books.length; i++) {
            if (books[i] != null && books[i].getPrice() <= maxPrice) {
                books[i].displayBookInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No books found under this price.");
        }
    }

    public static void searchBook(Book[] books, String author, String category) {
        System.out.println("\nSearch results for Author: " + author + " and Category: " + category);
        String a = author.trim().toLowerCase();
        String c = category.trim().toLowerCase();
        boolean found = false;

        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                if (books[i].getAuthor().toLowerCase().contains(a) && 
                    books[i].getCategory().toLowerCase().contains(c)) {
                    books[i].displayBookInfo();
                    found = true;
                }
            }
        }
        if (!found) {
            System.out.println("No matching books found.");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Book[] library = new Book[6];
        library[0] = new PrintedBook("To Kill a Mockingbird", "Harper Lee", "978-0061120084", 450.0, "Fiction", 336);
        library[1] = new EBook("Wings of Fire", "A.P.J. Abdul Kalam", "978-8173711466", 199.0, "Autobiography", 4.2, "PDF");
        library[2] = new PrintedBook("1984", "George Orwell", "978-0451524935", 350.0, "Fiction", 328);
        library[3] = new EBook("Animal Farm", "George Orwell", "978-0451526342", 150.0, "Fiction", 2.1, "EPUB");
        library[4] = new PrintedBook("Clean Code", "Robert C. Martin", "978-0132350884", 850.0, "Technology", 464);
        library[5] = new EBook("Effective Java", "Joshua Bloch", "978-0134685991", 620.0, "Technology", 6.8, "PDF");

        System.out.println("Books in Library:");
        for (int i = 0; i < library.length; i++) {
            if (library[i] != null) {
                System.out.print((i + 1) + ". ");
                library[i].displayBookInfo();
            }
        }

        System.out.println("\nAdding reviews:");
        library[0].addReview("Rajesh Gupta", 5, "Great book.");
        library[0].addReview("Sneha Rao", 4, "Good read.");
        library[1].addReview("Vikram Mehta", 5, "Very inspiring.");

        library[0].displayReviews();
        System.out.println();
        library[1].displayReviews();

        System.out.println("\nTesting Overloaded Searches:");
        searchBook(library, "Orwell");
        searchBook(library, 300.0);
        searchBook(library, "Robert C. Martin", "Technology");

        System.out.println("\nCatalog Summary (using StringBuilder):");
        StringBuilder catalog = new StringBuilder();
        for (int i = 0; i < library.length; i++) {
            if (library[i] != null) {
                catalog.append("- ").append(library[i].getTitle())
                       .append(" by ").append(library[i].getAuthor())
                       .append(" (Rs. ").append(library[i].getPrice()).append(")\n");
            }
        }
        System.out.print(catalog.toString());

        System.out.println("\nInteractive Search Menu:");
        System.out.println("1. Search by Keyword");
        System.out.println("2. Search by Max Price");
        System.out.println("3. Search by Author and Category");
        System.out.println("4. Exit");
        System.out.print("Enter choice: ");

        int choice = sc.nextInt();
        sc.nextLine();

        switch (choice) {
            case 1:
                System.out.print("Enter keyword: ");
                String kw = sc.nextLine();
                searchBook(library, kw);
                break;
            case 2:
                System.out.print("Enter max price: ");
                double p = sc.nextDouble();
                sc.nextLine();
                searchBook(library, p);
                break;
            case 3:
                System.out.print("Enter author: ");
                String auth = sc.nextLine();
                System.out.print("Enter category: ");
                String cat = sc.nextLine();
                searchBook(library, auth, cat);
                break;
            case 4:
                break;
            default:
                System.out.println("Invalid choice.");
        }

        sc.close();
    }
}
