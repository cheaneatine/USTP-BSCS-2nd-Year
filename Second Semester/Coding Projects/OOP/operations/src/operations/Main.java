package operations;

public class Main {
    public static void main(String[] args) {
        Operations operations = new Operations();

        double a = 10.0;
        double b = 5.0;

        System.out.println("Addition: " + operations.add(a, b));
        System.out.println("Subtraction: " + operations.subtract(a, b));
        System.out.println("Multiplication: " + operations.multiply(a, b));
        System.out.println("Division: " + operations.divide(a, b));
    }
}
