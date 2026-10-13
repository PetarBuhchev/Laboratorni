import java.util.Scanner;

public class task3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] words = new String[5];

        System.out.print("Enter 5 strings separated by space: ");
        for (int i = 0; i < 5; i++) {
            words[i] = scanner.next();
        }

        System.out.println("\nStrings in the array:");
        for (int i = 0; i < 5; i++) {
            System.out.println(words[i]);
        }

        scanner.close();
    }
}
