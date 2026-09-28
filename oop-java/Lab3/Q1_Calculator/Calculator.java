public class Calculator {
    private double num1;
    private double num2;

    public Calculator() {
        this.num1 = 0.0;
        this.num2 = 0.0;
    }

    public Calculator(double num1, double num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    public double getNum1() {
        return num1;
    }

    public double getNum2() {
        return num2;
    }

    public double add() {
        return num1 + num2;
    }

    public double subtract() {
        return num1 - num2;
    }

    public double multiply() {
        return num1 * num2;
    }

    public double divide() {
        if (num2 == 0) {
            System.out.println("Division by zero error");
            return 0.0;
        }
        return num1 / num2;
    }
}
