package booksystem.model;

public class PrintedBook extends Book {
    private int numberOfPages;

    public PrintedBook(String title, String author, String isbn, double price, String category, int numberOfPages) {
        super(title, author, isbn, price, category);
        this.numberOfPages = numberOfPages;
    }

    public int getNumberOfPages() {
        return numberOfPages;
    }

    public void setNumberOfPages(int numberOfPages) {
        this.numberOfPages = numberOfPages;
    }

    @Override
    public void displayBookInfo() {
        System.out.println("[Printed Book] " + title + " | " + author + " | " + isbn + " | Rs." + price + 
                           " | " + category + " | Pages: " + numberOfPages);
    }
}
