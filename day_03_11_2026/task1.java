package day_03_11_2026;

import java.util.Scanner;

public class task1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        System.out.println("Welcome to the program. If you want to exit please type \"EXIT\"");
        String EMAIL_PATTERN = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"

                + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
        String ASS_PATTERN = "^ass$";
        int countAss = 0;
        int countEmail = 0;
        String str = "";
        do {
            str = scn.nextLine();
            sb.append(str + " ");
            if (str.matches(ASS_PATTERN)) {
                countAss++;
            } else if (str.matches(EMAIL_PATTERN)) {
                countEmail++;
            }
        } while (!str.equals("Exit"));

        System.out.println(sb);
        System.out.println("Emails: " + countEmail);
        System.out.println("Asses:" + countAss);

        String[] words = sb.toString().trim().split(" ");

        StringBuilder result = new StringBuilder();

        for (int i = words.length - 1; i >= 0; i--) {
            result.append(words[i]);

            if (i > 0) {
                result.append(" ");
            }
        }

        System.out.println(result);
    }
}
