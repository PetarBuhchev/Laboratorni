
import java.util.Scanner;

public class myFirstClass {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter name: ");
        String name = scanner.nextLine();

        System.out.print("Enter age: ");
        int age = scanner.nextInt();
        scanner.nextLine(); // изчистване на новия ред

        System.out.print("Enter birth date: ");
        String birthDate = scanner.nextLine();

        System.out.println("\nEntered data:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Birth date: " + birthDate);

        scanner.close();
    }
}