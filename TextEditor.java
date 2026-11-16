import java.io.*;
import java.util.Scanner;

public class TextEditor {

    public static void main(String[] args) {
        //Създаваш си скенер за Input
        Scanner sc = new Scanner(System.in);
        //Създаваш празен стринг в който ще записваш неща до момента в който не запазваш във файл, както и инт за избора в менюто   

        String text = "";
        int choice;

        do {
            System.out.println("\n===== МИНИ ТЕКСТОВ РЕДАКТОР =====");
            System.out.println("1. Добавяне на текст");
            System.out.println("2. Замяна на дума");
            System.out.println("3. Търсене на стринг");
            System.out.println("4. Запис във файл");
            System.out.println("5. Четене от файл");
            System.out.println("0. Изход");
            System.out.print("Избор: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Въведете текст: ");
                    text += sc.nextLine() + "\n";
                    System.out.println("Текстът е добавен.");
                    break;

                case 2:
                    //Тук идеята е че имамем стринг, да си представим че е израза "Hello, World!"
                    //Искаме обаче да заменим думата "World" с "Java"
                    //Първо питаме потребителя коя дума иска да замени, след това с каква дума иска да я замени
                    //Съответно старата и новата дума ги запазваме в променливите oldWord и newWord
                    //След което използваме метода replace() на стринга text за да извършим замяната
                    System.out.print("Коя дума да се замени: ");
                    String oldWord = sc.nextLine();

                    System.out.print("С каква дума: ");
                    String newWord = sc.nextLine();

                    text = text.replace(oldWord, newWord);
                    System.out.println("Замяната е извършена.");
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
        }
                    break;

                case 4:
                    try {
                        // Текстов файл
                        FileWriter fw = new FileWriter("text.txt");
                        fw.write(text);
                        fw.close();

                        // Бинарен файл
                        DataOutputStream dos =
                                new DataOutputStream(
                                        new FileOutputStream("text.bin"));

                        dos.writeUTF(text);
                        dos.close();

                        System.out.println("Запис успешно.");
                    } catch (IOException e) {
                        System.out.println("Грешка при запис.");
                    }
                    break;

                case 5:
                    System.out.println("1. Четене от текстов файл");
                    System.out.println("2. Четене от бинарен файл");
                    int fileChoice = sc.nextInt();
                    sc.nextLine();

                    try {
                        if (fileChoice == 1) {
                            BufferedReader br =
                                    new BufferedReader(
                                            new FileReader("text.txt"));

                            String line;
                            text = "";

                            while ((line = br.readLine()) != null) {
                                text += line + "\n";
                            }

                            br.close();
                        } else if (fileChoice == 2) {
                            DataInputStream dis =
                                    new DataInputStream(
                                            new FileInputStream("text.bin"));

                            text = dis.readUTF();
                            dis.close();
                        }

                        System.out.println("\nСъдържание:");
                        System.out.println(text);

                    } catch (IOException e) {
                        System.out.println("Грешка при четене.");
                    }
                    break;

                case 0:
                    System.out.println("Край на програмата.");
                    break;

                default:
                    System.out.println("Невалиден избор!");
            }

        } while (choice != 0);

        sc.close();
    }
}