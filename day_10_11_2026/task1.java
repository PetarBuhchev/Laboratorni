package day_10_11_2026;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class task1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        System.out.println("Welcome to the program. If you want to exit please type \"Exit\"");
        String EMAIL_PATTERN = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"

                + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
        String str = "";
        ArrayList<String> emails = new ArrayList<String>();
        String choice = "";
        do {
            System.out.println("\nChoose an option: 1 - Add email, 2 - Show emails from file, Exit - Stop");
            choice = scn.nextLine();

            switch (choice) {
                case "1":
                    System.out.print("Enter email: ");
                    str = scn.nextLine();
                    sb.append(str + " ");
                    if (str.matches(EMAIL_PATTERN)) {
                        emails.clear();
                        try {
                            File file = new File("test.txt");
                            if (file.exists()) {
                                InputStream is = new FileInputStream(file);
                                int size = is.available();
                                StringBuilder currentEmail = new StringBuilder();

                                for (int i = 0; i < size; i++) {
                                    char c = (char) is.read();
                                    if (c == '\n') {
                                        emails.add(currentEmail.toString());
                                        currentEmail.setLength(0);
                                    } else if (c != '\r') {
                                        currentEmail.append(c);
                                    }
                                }
                                if (currentEmail.length() > 0) {
                                    emails.add(currentEmail.toString());
                                }
                                is.close();
                            }

                            emails.add(str);

                            OutputStream os = new FileOutputStream("test.txt");
                            for (String email : emails) {
                                os.write(email.getBytes());
                                os.write('\n');
                            }
                            os.close();
                            System.out.println("Email added successfully.");
                        } catch (IOException e) {
                            System.out.println("Exception");
                        }
                    } else {
                        System.out.println("Invalid email.");
                    }
                    break;

                case "2":
                    try {
                        File file = new File("test.txt");
                        if (file.exists()) {
                            InputStream is = new FileInputStream(file);
                            int size = is.available();
                            for (int i = 0; i < size; i++) {
                                System.out.print((char) is.read());
                            }
                            is.close();
                        } else {
                            System.out.println("File is empty.");
                        }
                    } catch (IOException e) {
                        System.out.println("Exception");
                    }
                    break;

                case "Exit":
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid option. Please choose 1, 2, or Exit.");
                    break;
            }
        } while (!choice.equals("Exit"));
    }
}
