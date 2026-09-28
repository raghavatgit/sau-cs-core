package booksystem.model;

public class EBook extends Book {
    private double fileSizeMB;
    private String fileFormat;

    public EBook(String title, String author, String isbn, double price, String category, 
                 double fileSizeMB, String fileFormat) {
        super(title, author, isbn, price, category);
        this.fileSizeMB = fileSizeMB;
        this.fileFormat = fileFormat;
    }

    public double getFileSizeMB() {
        return fileSizeMB;
    }

    public void setFileSizeMB(double fileSizeMB) {
        this.fileSizeMB = fileSizeMB;
    }

    public String getFileFormat() {
        return fileFormat;
    }

    public void setFileFormat(String fileFormat) {
        this.fileFormat = fileFormat;
    }

    @Override
    public void displayBookInfo() {
        System.out.println("[EBook] " + title + " | " + author + " | " + isbn + " | Rs." + price + 
                           " | " + category + " | Size: " + fileSizeMB + "MB | Format: " + fileFormat);
    }
}
