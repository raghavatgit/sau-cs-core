public class StudentApp {
    public static void main(String[] args) {
        System.out.println("University: " + Student.getUniversityName());
        System.out.println("Initial student count: " + Student.getTotalStudents());
        System.out.println();

        Student s1 = new Student(101, "Alice Sharma", "Computer Science");
        Student s2 = new Student(102, "Bob Patel", "Information Technology");
        Student s3 = new Student(103, "Charlie Verma", "Electronics");

        s1.displayStudent();
        s2.displayStudent();
        s3.displayStudent();

        System.out.println("Total registered students: " + Student.getTotalStudents());
        System.out.println();

        s1.setDepartment("Artificial Intelligence");
        System.out.println("Updated student 1:");
        s1.displayStudent();

        Student.setUniversityName("National University");
        System.out.println("After changing university name:");
        s2.displayStudent();
    }
}
