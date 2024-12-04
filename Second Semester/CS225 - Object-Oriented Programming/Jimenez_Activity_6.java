import java.util.Scanner;

public class Jimenez_Activity_6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int x = scanner.nextInt();

        System.out.print("Enter the second number: ");
        int y = scanner.nextInt();

        System.out.println(x + " + " + y + " = " + (x + y));
        System.out.println(x + " - " + y + " = " + (x - y));
        System.out.println(x + " x " + y + " = " + (x * y));

        if (y != 0) {
            System.out.println(x + " / " + y + " = " + (x / y));
            System.out.println(x + " mod " + y + " = " + (x % y));
        } else {
            System.out.println("Cannot divide by zero.");
        }

        scanner.close();
    }
}
