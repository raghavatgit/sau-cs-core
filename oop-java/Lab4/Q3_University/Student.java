public class Student {
    private String studentId;
    private String name;
    private String program;
    private String email;

    public Student(String studentId, String name, String program, String email) {
        this.studentId = studentId.trim();
        this.name = name.trim();
        this.program = program.trim();
        this.email = email.trim().toLowerCase();
    }

    public String getStudentId() {
        return studentId;
    }

    public void setStudentId(String studentId) {
        this.studentId = studentId.trim();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name.trim();
    }

    public String getProgram() {
        return program;
    }

    public void setProgram(String program) {
        this.program = program.trim();
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email.trim().toLowerCase();
    }

    public void displayInfo() {
        System.out.println("ID: " + studentId + " | Name: " + name + 
                           " | Program: " + program + " | Email: " + email);
    }
}
