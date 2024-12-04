import java.util.Scanner;

public class Jimenez_Activity_2 {
    public static void main(String[] args) {
        // Create a Scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the first number
        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

        // Prompt the user to enter the second number
        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();

        // Close the Scanner to prevent resource leak
        scanner.close();

        // Calculate the sum
        int sum = num1 + num2;

        // Display the result
        System.out.println(num1 + " + " + num2 + " = " + sum);
    }
}
