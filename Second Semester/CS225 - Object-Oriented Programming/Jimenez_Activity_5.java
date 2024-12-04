import java.util.Scanner;

public class Jimenez_Activity_5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int x = scanner.nextInt();

        System.out.print("Enter the second number: ");
        int y = scanner.nextInt();

        int product = x * y;

        System.out.println("Product: " + product);

        scanner.close();
    }
}
