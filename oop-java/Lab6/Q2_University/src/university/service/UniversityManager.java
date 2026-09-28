package university.service;

import university.model.Student;
import university.model.Course;
import java.util.Map;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;

public class UniversityManager {
    private Map<String, Student> students;
    private Map<String, Course> courses;
    private Map<String, Set<String>> studentRegistrations;
    private Map<String, Set<String>> courseRegistrations;

    public UniversityManager() {
        this.students = new LinkedHashMap<>();
        this.courses = new LinkedHashMap<>();
        this.studentRegistrations = new HashMap<>();
        this.courseRegistrations = new HashMap<>();
    }

    public boolean addStudent(Student s) {
        if (s == null) return false;
        String id = s.getStudentId().toUpperCase();
        if (students.containsKey(id)) {
            System.out.println("Error: Duplicate student ID " + s.getStudentId() + " not allowed.");
            return false;
        }
        students.put(id, s);
        studentRegistrations.put(id, new LinkedHashSet<>());
        System.out.println("Student added: " + s.getName() + " (" + s.getStudentId() + ")");
        return true;
    }

    public boolean removeStudent(String studentId) {
        String id = studentId.trim().toUpperCase();
        if (!students.containsKey(id)) {
            System.out.println("Error: Student ID " + studentId + " not found.");
            return false;
        }

        Set<String> registeredCourses = studentRegistrations.get(id);
        if (registeredCourses != null) {
            for (String code : registeredCourses) {
                Set<String> set = courseRegistrations.get(code);
                if (set != null) {
                    set.remove(id);
                }
            }
        }

        studentRegistrations.remove(id);
        Student removed = students.remove(id);
        System.out.println("Student removed: " + removed.getName() + " (" + id + ")");
        return true;
    }

    public boolean addCourse(Course c) {
        if (c == null) return false;
        String code = c.getCourseCode().toUpperCase();
        if (courses.containsKey(code)) {
            System.out.println("Error: Duplicate course code " + c.getCourseCode() + " not allowed.");
            return false;
        }
        courses.put(code, c);
        courseRegistrations.put(code, new LinkedHashSet<>());
        System.out.println("Course added: " + c.getCourseName() + " (" + c.getCourseCode() + ")");
        return true;
    }

    public boolean removeCourse(String courseCode) {
        String code = courseCode.trim().toUpperCase();
        if (!courses.containsKey(code)) {
            System.out.println("Error: Course code " + courseCode + " not found.");
            return false;
        }

        Set<String> enrolledStudents = courseRegistrations.get(code);
        if (enrolledStudents != null) {
            for (String sid : enrolledStudents) {
                Set<String> set = studentRegistrations.get(sid);
                if (set != null) {
                    set.remove(code);
                }
            }
        }

        courseRegistrations.remove(code);
        Course removed = courses.remove(code);
        System.out.println("Course removed: " + removed.getCourseName() + " (" + code + ")");
        return true;
    }

    public boolean registerStudentForCourse(String studentId, String courseCode) {
        String sId = studentId.trim().toUpperCase();
        String cCode = courseCode.trim().toUpperCase();

        if (!students.containsKey(sId)) {
            System.out.println("Error: Student ID " + studentId + " not found.");
            return false;
        }
        if (!courses.containsKey(cCode)) {
            System.out.println("Error: Course code " + courseCode + " not found.");
            return false;
        }

        Set<String> enrolledCourses = studentRegistrations.get(sId);
        if (enrolledCourses.contains(cCode)) {
            System.out.println("Error: Student is already registered in course " + cCode + ".");
            return false;
        }

        Course course = courses.get(cCode);
        Set<String> enrolledStudents = courseRegistrations.get(cCode);
        if (enrolledStudents.size() >= course.getMaxCapacity()) {
            System.out.println("Error: Course " + cCode + " is full. Capacity: " + course.getMaxCapacity());
            return false;
        }

        enrolledCourses.add(cCode);
        enrolledStudents.add(sId);
        System.out.println("Successfully registered student " + sId + " in course " + cCode + ".");
        return true;
    }

    public boolean withdrawStudentFromCourse(String studentId, String courseCode) {
        String sId = studentId.trim().toUpperCase();
        String cCode = courseCode.trim().toUpperCase();

        if (!students.containsKey(sId)) {
            System.out.println("Error: Student ID " + studentId + " not found.");
            return false;
        }
        if (!courses.containsKey(cCode)) {
            System.out.println("Error: Course code " + courseCode + " not found.");
            return false;
        }

        Set<String> enrolledCourses = studentRegistrations.get(sId);
        if (!enrolledCourses.contains(cCode)) {
            System.out.println("Error: Student " + sId + " is not registered in course " + cCode + ".");
            return false;
        }

        enrolledCourses.remove(cCode);
        courseRegistrations.get(cCode).remove(sId);
        System.out.println("Successfully withdrawn student " + sId + " from course " + cCode + ".");
        return true;
    }

    public void displayCoursesByStudent(String studentId) {
        String sId = studentId.trim().toUpperCase();
        if (!students.containsKey(sId)) {
            System.out.println("Student ID " + studentId + " not found.");
            return;
        }

        Student s = students.get(sId);
        System.out.println("\nCourses registered by " + s.getName() + " (" + sId + "):");
        Set<String> registered = studentRegistrations.get(sId);
        if (registered == null || registered.isEmpty()) {
            System.out.println("No courses registered.");
            return;
        }

        int count = 1;
        for (String code : registered) {
            Course c = courses.get(code);
            if (c != null) {
                System.out.print(count++ + ". ");
                c.displayInfo();
            }
        }
    }

    public void displayStudentsInCourse(String courseCode) {
        String cCode = courseCode.trim().toUpperCase();
        if (!courses.containsKey(cCode)) {
            System.out.println("Course code " + courseCode + " not found.");
            return;
        }

        Course c = courses.get(cCode);
        System.out.println("\nStudents registered in " + c.getCourseName() + " (" + cCode + "):");
        Set<String> enrolled = courseRegistrations.get(cCode);
        if (enrolled == null || enrolled.isEmpty()) {
            System.out.println("No students registered.");
            return;
        }

        int count = 1;
        for (String sid : enrolled) {
            Student s = students.get(sid);
            if (s != null) {
                System.out.print(count++ + ". ");
                s.displayInfo();
            }
        }
    }

    public void filterStudentsByProgram(String program) {
        String p = program.trim().toLowerCase();
        System.out.println("\nStudents in program: " + program);
        boolean found = false;
        for (Student s : students.values()) {
            if (s.getProgram().toLowerCase().contains(p)) {
                s.displayInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No students found in this program.");
        }
    }

    public void filterCoursesByCredits(int minCredits, int maxCredits) {
        System.out.println("\nCourses with credits between " + minCredits + " and " + maxCredits + ":");
        boolean found = false;
        for (Course c : courses.values()) {
            if (c.getCredits() >= minCredits && c.getCredits() <= maxCredits) {
                c.displayInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No courses found in this credit range.");
        }
    }

    public void displayEnrollmentStatistics() {
        System.out.println("\nEnrollment Statistics:");
        System.out.println("Total Students: " + students.size());
        System.out.println("Total Courses: " + courses.size());

        System.out.println("\nCourse Enrollment Details:");
        for (Course c : courses.values()) {
            String code = c.getCourseCode();
            int enrolled = courseRegistrations.get(code).size();
            int available = c.getMaxCapacity() - enrolled;
            System.out.println(code + " - " + c.getCourseName() + ": Registered: " + 
                               enrolled + ", Available Seats: " + available + ", Capacity: " + c.getMaxCapacity());
        }

        System.out.println("\nCourses with no registered students:");
        boolean noneEmpty = true;
        for (Course c : courses.values()) {
            String code = c.getCourseCode();
            if (courseRegistrations.get(code).isEmpty()) {
                System.out.println("- " + code + ": " + c.getCourseName());
                noneEmpty = false;
            }
        }
        if (noneEmpty) {
            System.out.println("None (all courses have at least one registered student).");
        }
    }

    public void displayAllStudents() {
        System.out.println("\nAll Registered Students (" + students.size() + "):");
        if (students.isEmpty()) {
            System.out.println("No students found.");
            return;
        }
        int i = 1;
        for (Student s : students.values()) {
            System.out.print(i++ + ". ");
            s.displayInfo();
        }
    }

    public void displayAllCourses() {
        System.out.println("\nAll Available Courses (" + courses.size() + "):");
        if (courses.isEmpty()) {
            System.out.println("No courses found.");
            return;
        }
        int i = 1;
        for (Course c : courses.values()) {
            System.out.print(i++ + ". ");
            c.displayInfo();
        }
    }

    public void searchStudentById(String id) {
        String sid = id.trim().toUpperCase();
        if (students.containsKey(sid)) {
            System.out.println("Student found:");
            students.get(sid).displayInfo();
        } else {
            System.out.println("No student found with ID: " + id);
        }
    }

    public void searchStudentByName(String name) {
        String q = name.trim().toLowerCase();
        System.out.println("\nMatching students for: " + name);
        boolean found = false;
        for (Student s : students.values()) {
            if (s.getName().toLowerCase().contains(q)) {
                s.displayInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No matching students found.");
        }
    }

    public void searchCourse(String query) {
        String q = query.trim().toLowerCase();
        System.out.println("\nMatching courses for: " + query);
        boolean found = false;
        for (Course c : courses.values()) {
            if (c.getCourseCode().toLowerCase().contains(q) || c.getCourseName().toLowerCase().contains(q)) {
                c.displayInfo();
                found = true;
            }
        }
        if (!found) {
            System.out.println("No matching courses found.");
        }
    }
}
