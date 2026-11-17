import java.io.*;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class text {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Създаваш празен стринг бюлдър в който ще записваш неща до момента в който не
        // запазваш във файл, както и инт за избора в менюто
        StringBuilder text = new StringBuilder();

        // 1. Зареждане на съществуващия текст от предишни стартирания на програмата
        loadInitialText(text);

        int choice;

        do {
            System.out.println("\n===== Text editor =====");
            System.out.println("1. Add text");
            System.out.println("2. Replace word");
            System.out.println("3. Reverse string");
            System.out.println("4. Save file");
            System.out.println("5. Read from file");
            System.out.println("0. Exit");
            System.out.print("Choise: ");

            choice = Integer.parseInt(sc.nextLine());

            switch (choice) {

                case 1:
                    System.out.println("Add text:");
                    text.append(sc.nextLine()).append("\n");
                    System.out.println("Text added.");
                    break;

                case 2:
                    // Тук идеята е че имамем стринг, да си представим че е израза "Hello, World!"
                    // Искаме обаче да заменим думата "World" с "Java"
                    // Първо питаме потребителя коя дума иска да замени, след това с каква дума иска
                    // да я замени
                    // Съответно старата и новата дума ги запазваме в променливите oldWord и newWord
                    // След което използваме метода replace() на стринга text за да извършим
                    // замяната
                    System.out.print("Which word to be replaced: ");
                    String oldWord = sc.nextLine();

                    System.out.print("New word: ");
                    String newWord = sc.nextLine();

                    String updatedText = text.toString().replace(oldWord, newWord);

                    text.setLength(0);
                    text.append(updatedText);

                    System.out.println("Replacement successful.");
                    break;

                case 3:
                    // Reverse на стринга дума по дума
                    // Правим си StringBuilder, който ще използваме за да съхраним резултата
                    String[] words = text.toString().trim().split(" ");

                    StringBuilder result = new StringBuilder();

                    for (int i = words.length - 1; i >= 0; i--) {
                        result.append(words[i]);
                        if (i > 0) {
                            result.append(" ");
                        }
                    }
                    System.out.println(result);
                    break;

                case 4:
                    // Имаме методи за записване във файл
                    saveTextFile(text.toString());
                    saveEmailsBinary(text.toString());
                    break;

                case 5:
                    System.out.println("1 - Reading from txt file");
                    System.out.println("2 - Reading from bin file");
                    System.out.print("Choice: ");

                    int fileChoice = Integer.parseInt(sc.nextLine());

                    if (fileChoice == 1) {
                        readTextFile();
                    } else if (fileChoice == 2) {
                        readBinaryEmails();
                    } else {
                        System.out.println("Invailic choice.");
                    }
                    break;

                case 0:
                    System.out.println("Exit from the app.");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 0);

        sc.close();
    }

    // Зареждане на съществуващ текст от файла при стартиране на програмата
    public static void loadInitialText(StringBuilder text) {
        File file = new File("text.txt");
        if (file.exists()) {
            try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                String line;
                while ((line = br.readLine()) != null) {
                    text.append(line).append("\n");
                }
                System.out.println("Loaded previous text from text.txt.");
            } catch (IOException e) {
                System.out.println("Error reading existing text: " + e.getMessage());
            }
        }
    }

    // Запис на текста в текстов файл
    public static void saveTextFile(String text) {
        try (FileWriter fw = new FileWriter("text.txt")) {
            fw.write(text);
            System.out.println("The text is saved in text.txt");
        } catch (IOException e) {
            System.out.println("Error in saving the text in txt.");
        }
    }

    // Запис на имейлите в бинарен файл
    public static void saveEmailsBinary(String text) {

        String EMAIL_PATTERN = "[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+";

        Pattern pattern = Pattern.compile(EMAIL_PATTERN);
        Matcher matcher = pattern.matcher(text);
        // Създаваме DataOutputStream, който ще използваме за записване на имейлите в
        // бинарен файл
        try {
            DataOutputStream dos = new DataOutputStream(
                    new FileOutputStream("emails.bin"));
            // Създаваме променлива count, която ще използваме за да броим колко имейла сме
            // записали в бинарния файл
            int count = 0;
            // Докато намерим имейл в текста, записваме го в бинарния файл и увеличаваме
            // брояча с 1
            while (matcher.find()) {
                dos.writeUTF(matcher.group());
                count++;
            }
            // Затваряме DataOutputStream, за да се запишат имейлите в бинарния файл
            dos.close();

            System.out.println(
                    count + " emails are saved in emails.bin");

        } catch (IOException e) {
            System.out.println("Error in saving .bin");
        }
    }

    // Четене на текстов файл
    public static void readTextFile() {
        // Създаваме BufferedReader, който ще използваме за четене на текстовия файл
        try {
            BufferedReader br = new BufferedReader(
                    new FileReader("text.txt"));
            // Създаваме променлива line, която ще използваме за да четем редовете от
            // текстовия файл
            String line;

            System.out.println("\n===== Text =====");
            // Докато има редове в текстoия файл, ги отпечатваме на конзолата
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            br.close();

        } catch (IOException e) {
            System.out.println("Error in reading.");
        }
    }

    // Четене на имейли от бинарния файл
    public static void readBinaryEmails() {
        // Създаваме DataInputStream, който ще използваме за четене на бинарния файл
        try {
            DataInputStream dis = new DataInputStream(
                    new FileInputStream("emails.bin"));

            System.out.println("\n===== Emails =====");

            while (true) {
                System.out.println(dis.readUTF());
            }

        } catch (EOFException e) {
            System.out.println("End of file.");
        } catch (IOException e) {
            System.out.println("Error in reading.");
        }
    }
}