import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

class ErrorInUsername extends Exception {
    ErrorInUsername(String error) {
        super(error);
    }
}

class ErrorUsernameIsEmpty extends Exception {
    ErrorUsernameIsEmpty(String error) {
        super(error);
    }
}

class ErrorPasswordIsEmpty extends Exception {
    ErrorPasswordIsEmpty(String error) {
        super(error);
    }
}

class ErrorInPassword extends Exception {
    ErrorInPassword(String error) {
        super(error);
    }
}

class User {
    private String username;
    private String password;

    public User(String username, String password) throws ErrorUsernameIsEmpty, ErrorPasswordIsEmpty {
        setUsername(username);
        setPassword(password);
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) throws ErrorUsernameIsEmpty {
        if (username == null || username.trim().isEmpty()) {
            throw new ErrorUsernameIsEmpty("The username should not be empty");
        }
        this.username = username;
    }

    public String getPassowrd() {
        return password;
    }

    public void setPassword(String password) throws ErrorPasswordIsEmpty {
        if (password == null || password.trim().isEmpty()) {
            throw new ErrorPasswordIsEmpty("The password should not be empty");
        }
        this.password = password;
    }

    @Override
    public String toString() {
        return "Username: " + username;
    }
}

public class task {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        List<User> users = new ArrayList<>();
        int choice = 0;
        System.out.println("Welcome to the app!");

        do {
            System.out.println("Please, choose between the options 1,2,3");
            System.out.println("1. Adds new user");
            System.out.println("2. Shows list of all users");
            System.out.println("3. Exit");

            try {
                choice = scn.nextInt();
                scn.nextLine();
            } catch (InputMismatchException e) {
                System.out.println("The choice must be number");
                scn.nextLine();
                choice = 0;
                continue;
            }

            switch (choice) {

                case 1:
                    try {
                        System.out.print("Input username: ");
                        String username = scn.nextLine();
                        if (!username.contains("@"))
                            throw new ErrorInUsername("Username should contain @");

                        System.out.print("Input password: ");
                        String password = scn.nextLine();
                        if (password.length() < 6)
                            throw new ErrorInPassword("Password should be 6 symbols long at least.");

                        User newUser = new User(username, password);
                        users.add(newUser);
                        System.out.println("The username is added successfully!");
                    } catch (Exception e) {
                        System.out.println("Error in validation: " + e.getMessage());
                    }
                    break;

                case 2:
                    System.out.println("\n---- USERS ----");
                    for (User user : users) {
                        System.out.println(user);
                    }
                    break;

                case 3:
                    System.out.println("Goodbye!");
                    break;

                default:
                    System.out.println("Incorrect choose! Pleae, choose a number between 1 and 3");
                    break;
            }
        } while (choice != 3);

        scn.close();
    }

}
