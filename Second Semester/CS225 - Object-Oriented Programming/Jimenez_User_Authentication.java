import java.util.Scanner;

public class Jimenez_User_Authentication {
    // Default credentials
    private static final String DEFAULT_USERNAME = "admin";
    private static final String DEFAULT_PASSWORD = "password";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Continuously prompt for username and password until correct credentials are
        // entered
        while (true) {
            System.out.println("Enter username:");
            String username = scanner.nextLine();

            System.out.println("Enter password:");
            String password = scanner.nextLine();

            if (authenticate(username, password)) {
                System.out.println("Authentication successful. Welcome, " + username + "!");
                break; // Exit the loop if authentication is successful
            } else {
                System.out.println("Incorrect username or password. Please try again.");
            }
        }

        scanner.close();
    }

    // Authenticates the entered username and password
    private static boolean authenticate(String username, String password) {
        return username.equals(DEFAULT_USERNAME) && password.equals(DEFAULT_PASSWORD);
    }
}