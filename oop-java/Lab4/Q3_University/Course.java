public class Course {
    private String courseCode;
    private String courseName;
    private int credits;

    public Course(String courseCode, String courseName, int credits) {
        this.courseCode = courseCode.trim().toUpperCase();
        this.courseName = courseName.trim();
        this.credits = credits;
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

    public void displayInfo() {
        System.out.println("Code: " + courseCode + " | Name: " + courseName + " | Credits: " + credits);
    }
}
