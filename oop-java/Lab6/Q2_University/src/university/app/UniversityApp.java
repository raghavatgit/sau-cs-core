package university.app;

import university.model.Student;
import university.model.Course;
import university.service.UniversityManager;
import java.util.Scanner;

public class UniversityApp {

    private static void loadSampleData(UniversityManager manager) {
        manager.addStudent(new Student("S101", "Aarav Sharma", "B.Tech CSE", "aarav@univ.edu"));
        manager.addStudent(new Student("S102", "Diya Patel", "B.Tech CSE", "diya@univ.edu"));
        manager.addStudent(new Student("S103", "Rohan Mehta", "B.Tech ECE", "rohan@univ.edu"));
        manager.addStudent(new Student("S104", "Ananya Verma", "MCA", "ananya@univ.edu"));
        manager.addStudent(new Student("S105", "Kabir Singh", "B.Tech CSE", "kabir@univ.edu"));

        // Creating courses with realistic maximum capacities
        manager.addCourse(new Course("CS101", "Object Oriented Programming in Java", 4, 3)); // capacity 3 to test limit
        manager.addCourse(new Course("CS102", "Data Structures and Algorithms", 4, 30));
        manager.addCourse(new Course("EC201", "Digital Signal Processing", 3, 20));
        manager.addCourse(new Course("MC301", "Database Management Systems", 4, 25));
        manager.addCourse(new Course("HU101", "Professional Ethics", 2, 40)); // course with 0 students initially

        // Pre-enrolling students to test capacity and multi-registration
        manager.registerStudentForCourse("S101", "CS101");
        manager.registerStudentForCourse("S101", "CS102");
        manager.registerStudentForCourse("S102", "CS101");
        manager.registerStudentForCourse("S103", "CS101"); // CS101 is now full (3/3)
        manager.registerStudentForCourse("S104", "MC301");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        UniversityManager manager = new UniversityManager();

        loadSampleData(manager);

        boolean running = true;
        while (running) {
            System.out.println("\nUniversity System Menu:");
            System.out.println("1. Add Student");
            System.out.println("2. Remove Student");
            System.out.println("3. Display All Students");
            System.out.println("4. Add Course");
            System.out.println("5. Remove Course");
            System.out.println("6. Display All Courses");
            System.out.println("7. Register Student for Course");
            System.out.println("8. Withdraw Student from Course");
            System.out.println("9. View Courses by Student");
            System.out.println("10. View Students in Course");
            System.out.println("11. Filter Students by Program");
            System.out.println("12. Filter Courses by Credit Range");
            System.out.println("13. Search Student (ID or Name)");
            System.out.println("14. Search Course");
            System.out.println("15. Display Enrollment Statistics");
            System.out.println("16. Exit");
            System.out.print("Enter choice (1-16): ");

            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter Student ID: ");
                    String sid = sc.nextLine();
                    System.out.print("Enter Name: ");
                    String sname = sc.nextLine();
                    System.out.print("Enter Program: ");
                    String sprog = sc.nextLine();
                    System.out.print("Enter Email: ");
                    String semail = sc.nextLine();
                    manager.addStudent(new Student(sid, sname, sprog, semail));
                    break;

                case 2:
                    System.out.print("Enter Student ID to remove: ");
                    String remSid = sc.nextLine();
                    manager.removeStudent(remSid);
                    break;

                case 3:
                    manager.displayAllStudents();
                    break;

                case 4:
                    System.out.print("Enter Course Code: ");
                    String ccode = sc.nextLine();
                    System.out.print("Enter Course Name: ");
                    String cname = sc.nextLine();
                    System.out.print("Enter Credits: ");
                    int ccred = sc.nextInt();
                    System.out.print("Enter Max Capacity: ");
                    int ccap = sc.nextInt();
                    sc.nextLine();
                    manager.addCourse(new Course(ccode, cname, ccred, ccap));
                    break;

                case 5:
                    System.out.print("Enter Course Code to remove: ");
                    String remCode = sc.nextLine();
                    manager.removeCourse(remCode);
                    break;

                case 6:
                    manager.displayAllCourses();
                    break;

                case 7:
                    System.out.print("Enter Student ID: ");
                    String regSid = sc.nextLine();
                    System.out.print("Enter Course Code: ");
                    String regCode = sc.nextLine();
                    manager.registerStudentForCourse(regSid, regCode);
                    break;

                case 8:
                    System.out.print("Enter Student ID: ");
                    String wSid = sc.nextLine();
                    System.out.print("Enter Course Code: ");
                    String wCode = sc.nextLine();
                    manager.withdrawStudentFromCourse(wSid, wCode);
                    break;

                case 9:
                    System.out.print("Enter Student ID: ");
                    String qSid = sc.nextLine();
                    manager.displayCoursesByStudent(qSid);
                    break;

                case 10:
                    System.out.print("Enter Course Code: ");
                    String qCode = sc.nextLine();
                    manager.displayStudentsInCourse(qCode);
                    break;

                case 11:
                    System.out.print("Enter Program to filter: ");
                    String filtProg = sc.nextLine();
                    manager.filterStudentsByProgram(filtProg);
                    break;

                case 12:
                    System.out.print("Enter Minimum Credits: ");
                    int minC = sc.nextInt();
                    System.out.print("Enter Maximum Credits: ");
                    int maxC = sc.nextInt();
                    sc.nextLine();
                    manager.filterCoursesByCredits(minC, maxC);
                    break;

                case 13:
                    System.out.println("Search Student by: 1. ID  2. Name");
                    System.out.print("Enter choice (1/2): ");
                    int sType = sc.nextInt();
                    sc.nextLine();
                    if (sType == 1) {
                        System.out.print("Enter Student ID: ");
                        String id = sc.nextLine();
                        manager.searchStudentById(id);
                    } else {
                        System.out.print("Enter Student Name: ");
                        String name = sc.nextLine();
                        manager.searchStudentByName(name);
                    }
                    break;

                case 14:
                    System.out.print("Enter Course Code or Name: ");
                    String cquery = sc.nextLine();
                    manager.searchCourse(cquery);
                    break;

                case 15:
                    manager.displayEnrollmentStatistics();
                    break;

                case 16:
                    System.out.println("Exiting University System.");
                    running = false;
                    break;

                default:
                    System.out.println("Invalid option.");
            }
        }

        sc.close();
    }
}
