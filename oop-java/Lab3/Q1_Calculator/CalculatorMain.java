public class CalculatorMain {
    public static void main(String[] args) {
        Calculator c1 = new Calculator(25.0, 5.0);
        System.out.println("First Calculator:");
        System.out.println("Number 1: " + c1.getNum1());
        System.out.println("Number 2: " + c1.getNum2());
        System.out.println("Addition: " + c1.add());
        System.out.println("Subtraction: " + c1.subtract());
        System.out.println("Multiplication: " + c1.multiply());
        System.out.println("Division: " + c1.divide());

        System.out.println();

        Calculator c2 = new Calculator(14.5, 2.5);
        System.out.println("Second Calculator:");
        System.out.println("Number 1: " + c2.getNum1());
        System.out.println("Number 2: " + c2.getNum2());
        System.out.println("Addition: " + c2.add());
        System.out.println("Subtraction: " + c2.subtract());
        System.out.println("Multiplication: " + c2.multiply());
        System.out.println("Division: " + c2.divide());

        System.out.println();

        Calculator c3 = new Calculator(50.0, 0.0);
        System.out.println("Third Calculator (zero division):");
        System.out.println("Number 1: " + c3.getNum1());
        System.out.println("Number 2: " + c3.getNum2());
        System.out.println("Division: " + c3.divide());
    }
}
