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
        String ASS_PATTERN = "^ass$";
        int countAss = 0;
        int countEmail = 0;
        String str = "";
        ArrayList<String> emails = new ArrayList<String>();
        do {
            str = scn.nextLine();
            sb.append(str + " ");
            if (str.matches(ASS_PATTERN)) {
                countAss++;
            } else if (str.matches(EMAIL_PATTERN)) {
                countEmail++;
                emails.add(str);
            }
        } while (!str.equals("Exit"));

        try {
            InputStream is = new FileInputStream("test.txt");
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

            OutputStream os = new FileOutputStream("test.txt");

            for (String email : emails) {
                os.write(email.getBytes());
                os.write('\n');
            }

            os.close();
        } catch (IOException e) {
            System.out.print("Exception");
        }
    }
}
