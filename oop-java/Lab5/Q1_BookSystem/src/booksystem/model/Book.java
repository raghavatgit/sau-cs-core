package booksystem.model;

public class Book {
    protected String title;
    protected String author;
    protected String isbn;
    protected double price;
    protected String category;

    private Review[] reviews;
    private int reviewCount;

    public Book(String title, String author, String isbn, double price, String category) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.price = price;
        this.category = category;
        this.reviews = new Review[10];
        this.reviewCount = 0;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void displayBookInfo() {
        System.out.println(title + " | " + author + " | " + isbn + " | Rs." + price + " | " + category);
    }

    public class Review {
        private String reviewerName;
        private int rating;
        private String comment;

        public Review(String reviewerName, int rating, String comment) {
            this.reviewerName = reviewerName;
            this.rating = rating;
            this.comment = comment;
        }

        public void displayReview() {
            System.out.println("Review for " + Book.this.title + " by " + reviewerName + ": " + rating + "/5 - " + comment);
        }
    }

    public void addReview(String reviewerName, int rating, String comment) {
        if (reviewCount < reviews.length) {
            reviews[reviewCount++] = new Review(reviewerName, rating, comment);
        }
    }

    public void displayReviews() {
        System.out.println("Reviews for " + title + ":");
        if (reviewCount == 0) {
            System.out.println("No reviews yet.");
            return;
        }
        for (int i = 0; i < reviewCount; i++) {
            reviews[i].displayReview();
        }
    }
}
