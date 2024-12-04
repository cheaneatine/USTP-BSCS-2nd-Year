import java.util.Scanner;

public class Jimenez_Activity_3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the dividend: ");
        int dividend = scanner.nextInt();

        System.out.print("Enter the divisor: ");
        int divisor = scanner.nextInt();

        int quotient = dividend / divisor;

        System.out.println("Result: " + quotient);

        scanner.close();
    }
}
