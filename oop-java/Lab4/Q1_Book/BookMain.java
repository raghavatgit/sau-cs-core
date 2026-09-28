import java.util.Scanner;

public class BookMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Book[] books = new Book[8];
        books[0] = new Book("To Kill a Mockingbird", "Harper Lee", "978-0061120084", 450.0, "Fiction");
        books[1] = new Book("Wings of Fire", "A.P.J. Abdul Kalam", "978-8173711466", 299.0, "Autobiography");
        books[2] = new Book("1984", "George Orwell", "978-0451524935", 350.0, "Fiction");
        books[3] = new Book("Animal Farm", "George Orwell", "978-0451526342", 220.0, "Fiction");
        books[4] = new Book("The Story of My Experiments with Truth", "Mahatma Gandhi", "978-8172290085", 199.0, "Autobiography");
        books[5] = new Book("Ignited Minds", "A.P.J. Abdul Kalam", "978-0143424123", 250.0, "Inspirational");
        books[6] = new Book("The Alchemist", "Paulo Coelho", "978-0062315007", 320.0, "Fiction");
        books[7] = new Book("Clean Code", "Robert C. Martin", "978-0132350884", 850.0, "Technology");

        StringBuilder sb = new StringBuilder();
        sb.append("Book List:\n");
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                sb.append(i + 1).append(". ").append(books[i].getTitle())
                  .append(" by ").append(books[i].getAuthor()).append("\n");
            }
        }
        String listString = sb.toString();
        System.out.println(listString);

        System.out.print("Enter search keyword: ");
        String keyword = sc.nextLine().trim().toLowerCase();

        System.out.println("Search Results:");
        boolean found = false;
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                String t = books[i].getTitle().toLowerCase();
                String a = books[i].getAuthor().toLowerCase();
                if (t.contains(keyword) || a.contains(keyword)) {
                    System.out.println(books[i].getTitle() + " by " + books[i].getAuthor());
                    found = true;
                }
            }
        }
        if (!found) {
            System.out.println("No matching books found.");
        }
        System.out.println();

        System.out.println("String Immutability Test:");
        String title = books[0].getTitle();
        System.out.println("Original title: " + title);
        title.concat(" Special Edition");
        System.out.println("Title after calling concat without reassigning: " + title);
        String updatedTitle = title.concat(" Special Edition");
        System.out.println("Title when assigned to new variable: " + updatedTitle);

        sc.close();
    }
}
