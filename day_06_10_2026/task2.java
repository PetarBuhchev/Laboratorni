
import java.util.Scanner;

public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.print("Enter length: ");
    int len = s.nextInt();

    System.out.print("Enter width: ");
    int wid = s.nextInt();

    System.out.println("Area of rectangle is: " + len * wid);

    s.close();

}
