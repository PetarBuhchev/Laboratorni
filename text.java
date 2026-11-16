import java.io.*;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class text {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        
        //Създаваш празен стринг бюлдър в който ще записваш неща до момента в който не запазваш във файл, както и инт за избора в менюто
        StringBuilder text = new StringBuilder();

        int choice;

        do {
            System.out.println("\n===== МИНИ ТЕКСТОВ РЕДАКТОР =====");
            System.out.println("1. Добавяне на текст");
            System.out.println("2. Подмяна на дума");
            System.out.println("3. Търсене на стринг");
            System.out.println("4. Запазване във файлове");
            System.out.println("5. Четене от файловете");
            System.out.println("0. Изход");
            System.out.print("Избор: ");

            choice = Integer.parseInt(sc.nextLine());

            switch (choice) {

                case 1:
                    System.out.println("Въведете текст:");
                    text.append(sc.nextLine()).append("\n");
                    System.out.println("Текстът е добавен.");
                    break;

                case 2:
                    //Тук идеята е че имамем стринг, да си представим че е израза "Hello, World!"
                    //Искаме обаче да заменим думата "World" с "Java"
                    //Първо питаме потребителя коя дума иска да замени, след това с каква дума иска да я замени
                    //Съответно старата и новата дума ги запазваме в променливите oldWord и newWord
                    //След което използваме метода replace() на стринга text за да извършим замяната
                    System.out.print("Коя дума да бъде заменена: ");
                    String oldWord = sc.nextLine();

                    System.out.print("Нова дума: ");
                    String newWord = sc.nextLine();

                    String updatedText =
                            text.toString().replace(oldWord, newWord);

                    text.setLength(0);
                    text.append(updatedText);

                    System.out.println("Замяната е успешна.");
                    break;

                case 3:
                    //Reverse на стринга дума по дума
                    //Правим си StringBuilder, който ще използваме за да съхраним резултата
                    StringBuilder result = new StringBuilder();
                    //Обхождаме стринга text отзад напред, като добавяме всеки символ в резултата
                    for (int i = text.length() - 1; i >= 0; i--) {
                        result.append(text.charAt(i));
                    //Добавяме интервал между думите, за да не се слепят
                    if (i > 0) {
                        result.append(" ");
                    }
                    System.out.println("Обърнат текст: " + result.toString());
                    break;

                case 4:
                    //Имаме методи за записване във файл
                    saveTextFile(text.toString());
                    saveEmailsBinary(text.toString());
                    break;

                case 5:
                    System.out.println("1 - Четене от текстов файл");
                    System.out.println("2 - Четене от бинарен файл");
                    System.out.print("Избор: ");

                    int fileChoice = Integer.parseInt(sc.nextLine());

                    if (fileChoice == 1) {
                        readTextFile();
                    } else if (fileChoice == 2) {
                        readBinaryEmails();
                    } else {
                        System.out.println("Невалиден избор.");
                    }
                    break;

                case 0:
                    System.out.println("Изход от програмата.");
                    break;

                default:
                    System.out.println("Невалиден избор!");
            }

        } while (choice != 0);

        sc.close();
    }

    // Запис на текста в текстов файл
    public static void saveTextFile(String text) {
        //Правим обект на FileWriter, който ще използваме за записване на текст във файл
        try {
            FileWriter fw = new FileWriter("text.txt");
            fw.write(text);
            //Затваряме FileWriter, за да се запази текста във файла
            fw.close();

            System.out.println("Текстът е записан в text.txt");
        } catch (IOException e) {
            System.out.println("Грешка при запис на текстов файл.");
        }
    }

    // Запис на имейлите в бинарен файл
    public static void saveEmailsBinary(String text) {

        String EMAIL_PATTERN =
                "[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+";

        Pattern pattern = Pattern.compile(EMAIL_PATTERN);
        Matcher matcher = pattern.matcher(text);
        //Създаваме DataOutputStream, който ще използваме за записване на имейлите в бинарен файл
        try {
            DataOutputStream dos =
                    new DataOutputStream(
                            new FileOutputStream("emails.bin"));
            //Създаваме променлива count, която ще използваме за да броим колко имейла сме записали в бинарния файл
            int count = 0;
            //Докато намерим имейл в текста, записваме го в бинарния файл и увеличаваме брояча с 1
            while (matcher.find()) {
                dos.writeUTF(matcher.group());
                count++;
            }
            //Затваряме DataOutputStream, за да се запишат имейлите в бинарния файл
            dos.close();

            System.out.println(
                count + " имейла са записани в emails.bin");

        } catch (IOException e) {
            System.out.println("Грешка при запис на бинарен файл.");
        }
    }

    // Четене на текстов файл
    public static void readTextFile() {
        //Създаваме BufferedReader, който ще използваме за четене на текстовия файл
        try {
            BufferedReader br =
                    new BufferedReader(
                            new FileReader("text.txt"));
            //Създаваме променлива line, която ще използваме за да четем редовете от текстовия файл
            String line;

            System.out.println("\n===== СЪДЪРЖАНИЕ =====");
            //Докато има редове в текстoия файл, ги отпечатваме на конзолата
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            br.close();

        } catch (IOException e) {
            System.out.println("Грешка при четене.");
        }
    }

    // Четене на имейли от бинарния файл
    public static void readBinaryEmails() {
        //Създаваме DataInputStream, който ще използваме за четене на бинарния файл
        try {
            DataInputStream dis =
                    new DataInputStream(
                            new FileInputStream("emails.bin"));

            System.out.println("\n===== ИМЕЙЛИ =====");

            while (true) {
                System.out.println(dis.readUTF());
            }

        } catch (EOFException e) {
            System.out.println("Край на файла.");
        } catch (IOException e) {
            System.out.println("Грешка при четене.");
        }
    }
}