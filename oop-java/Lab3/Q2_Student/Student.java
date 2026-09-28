public class Student {
    private int rollNo;
    private String name;
    private String department;

    private static String universityName = "Tech University";
    private static int totalStudents = 0;

    public Student() {
        this.rollNo = 0;
        this.name = "Unknown";
        this.department = "None";
        totalStudents++;
    }

    public Student(int rollNo, String name, String department) {
        this.rollNo = rollNo;
        this.name = name;
        this.department = department;
        totalStudents++;
    }

    public int getRollNo() {
        return rollNo;
    }

    public void setRollNo(int rollNo) {
        this.rollNo = rollNo;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public void displayStudent() {
        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
        System.out.println("University: " + universityName);
        System.out.println();
    }

    public static int getTotalStudents() {
        return totalStudents;
    }

    public static String getUniversityName() {
        return universityName;
    }

    public static void setUniversityName(String name) {
        universityName = name;
    }
}
