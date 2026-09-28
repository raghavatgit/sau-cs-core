import java.util.Scanner;

public class UniversitySystem {
    private static Student[] students = new Student[50];
    private static int studentCount = 0;

    private static Course[] courses = new Course[30];
    private static int courseCount = 0;

    private static void loadSampleData() {
        students[studentCount++] = new Student("S101", "Aarav Sharma", "B.Tech CSE", "aarav@univ.edu");
        students[studentCount++] = new Student("S102", "Diya Patel", "B.Tech CSE", "diya@univ.edu");
        students[studentCount++] = new Student("S103", "Rohan Mehta", "B.Tech ECE", "rohan@univ.edu");
        students[studentCount++] = new Student("S104", "Ananya Verma", "MCA", "ananya@univ.edu");
        students[studentCount++] = new Student("S105", "Kabir Singh", "B.Tech CSE", "kabir@univ.edu");

        courses[courseCount++] = new Course("CS101", "Object Oriented Programming in Java", 4);
        courses[courseCount++] = new Course("CS102", "Data Structures and Algorithms", 4);
        courses[courseCount++] = new Course("EC201", "Digital Signal Processing", 3);
        courses[courseCount++] = new Course("MC301", "Database Management Systems", 4);
    }

    private static void addStudent(Scanner sc) {
        if (studentCount >= students.length) {
            System.out.println("Student list is full.");
            return;
        }
        System.out.print("Enter Student ID: ");
        String id = sc.nextLine();
        System.out.print("Enter Name: ");
        String name = sc.nextLine();
        System.out.print("Enter Program: ");
        String program = sc.nextLine();
        System.out.print("Enter Email: ");
        String email = sc.nextLine();

        students[studentCount++] = new Student(id, name, program, email);
        System.out.println("Student added.");
    }

    private static void displayAllStudents() {
        System.out.println("\nStudents list (" + studentCount + "):");
        if (studentCount == 0) {
            System.out.println("No students found.");
            return;
        }
        for (int i = 0; i < studentCount; i++) {
            System.out.print((i + 1) + ". ");
            students[i].displayInfo();
        }
    }

    private static void addCourse(Scanner sc) {
        if (courseCount >= courses.length) {
            System.out.println("Course list is full.");
            return;
        }
        System.out.print("Enter Course Code: ");
        String code = sc.nextLine();
        System.out.print("Enter Course Name: ");
        String name = sc.nextLine();
        System.out.print("Enter Credits: ");
        int credits = sc.nextInt();
        sc.nextLine();

        courses[courseCount++] = new Course(code, name, credits);
        System.out.println("Course added.");
    }

    private static void displayAllCourses() {
        System.out.println("\nCourses list (" + courseCount + "):");
        if (courseCount == 0) {
            System.out.println("No courses found.");
            return;
        }
        for (int i = 0; i < courseCount; i++) {
            System.out.print((i + 1) + ". ");
            courses[i].displayInfo();
        }
    }

    private static void searchStudentById(Scanner sc) {
        System.out.print("Enter Student ID: ");
        String queryId = sc.nextLine().trim();
        boolean found = false;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getStudentId().equalsIgnoreCase(queryId)) {
                System.out.println("Student found:");
                students[i].displayInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Student with ID " + queryId + " not found.");
        }
    }

    private static void searchStudentByName(Scanner sc) {
        System.out.print("Enter name to search: ");
        String query = sc.nextLine().trim().toLowerCase();
        boolean found = false;

        System.out.println("Matching students:");
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getName().toLowerCase().contains(query)) {
                students[i].displayInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No student found matching " + query);
        }
    }

    private static void searchCourse(Scanner sc) {
        System.out.print("Enter course code or name: ");
        String query = sc.nextLine().trim().toLowerCase();
        boolean found = false;

        System.out.println("Matching courses:");
        for (int i = 0; i < courseCount; i++) {
            String code = courses[i].getCourseCode().toLowerCase();
            String name = courses[i].getCourseName().toLowerCase();

            if (code.contains(query) || name.contains(query)) {
                courses[i].displayInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No course found matching " + query);
        }
    }

    private static void displayStatistics() {
        System.out.println("\nUniversity Statistics:");
        System.out.println("Total Students: " + studentCount);
        System.out.println("Total Courses: " + courseCount);

        int totalCredits = 0;
        for (int i = 0; i < courseCount; i++) {
            totalCredits += courses[i].getCredits();
        }
        System.out.println("Total Credits: " + totalCredits);

        System.out.println("\nStudents per program:");
        String[] counted = new String[studentCount];
        int uniqueCount = 0;

        for (int i = 0; i < studentCount; i++) {
            String prog = students[i].getProgram();
            boolean exists = false;
            for (int j = 0; j < uniqueCount; j++) {
                if (counted[j].equalsIgnoreCase(prog)) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                counted[uniqueCount++] = prog;
                int count = 0;
                for (int k = 0; k < studentCount; k++) {
                    if (students[k].getProgram().equalsIgnoreCase(prog)) {
                        count++;
                    }
                }
                System.out.println(prog + ": " + count);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        loadSampleData();

        boolean running = true;
        while (running) {
            System.out.println("\nMenu:");
            System.out.println("1. Add Student");
            System.out.println("2. Display All Students");
            System.out.println("3. Add Course");
            System.out.println("4. Display All Courses");
            System.out.println("5. Search Student by ID");
            System.out.println("6. Search Student by Name");
            System.out.println("7. Search Course");
            System.out.println("8. Display Statistics");
            System.out.println("9. Exit");
            System.out.print("Enter choice: ");

            int option = sc.nextInt();
            sc.nextLine();

            switch (option) {
                case 1:
                    addStudent(sc);
                    break;
                case 2:
                    displayAllStudents();
                    break;
                case 3:
                    addCourse(sc);
                    break;
                case 4:
                    displayAllCourses();
                    break;
                case 5:
                    searchStudentById(sc);
                    break;
                case 6:
                    searchStudentByName(sc);
                    break;
                case 7:
                    searchCourse(sc);
                    break;
                case 8:
                    displayStatistics();
                    break;
                case 9:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }

        sc.close();
    }
}
