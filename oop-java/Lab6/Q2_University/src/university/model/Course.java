package university.model;

public class Course {
    private String courseCode;
    private String courseName;
    private int credits;
    private int maxCapacity;

    public Course(String courseCode, String courseName, int credits, int maxCapacity) {
        this.courseCode = courseCode.trim().toUpperCase();
        this.courseName = courseName.trim();
        this.credits = credits;
        this.maxCapacity = maxCapacity;
    }

    public Course(String courseCode, String courseName, int credits) {
        this(courseCode, courseName, credits, 30);
    }

    public String getCourseCode() {
        return courseCode;
    }

    public void setCourseCode(String courseCode) {
        this.courseCode = courseCode.trim().toUpperCase();
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName.trim();
    }

    public int getCredits() {
        return credits;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }

    public int getMaxCapacity() {
        return maxCapacity;
    }

    public void setMaxCapacity(int maxCapacity) {
        this.maxCapacity = maxCapacity;
    }

    public void displayInfo() {
        System.out.println("Code: " + courseCode + " | Name: " + courseName + 
                           " | Credits: " + credits + " | Capacity: " + maxCapacity);
    }
}
