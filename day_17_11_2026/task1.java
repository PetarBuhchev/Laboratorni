package day_17_11_2026;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;

        Person other = (Person) obj;

        if (this.hashCode() != other.hashCode()) {
            return false;
        }

        if (name == null) {
            if (other.name != null)
                return false;
        } else if (!name.equals(other.name)) {
            return false;
        }

        return true;
    }

    @Override
    public String toString() {
        return "Person{name='" + name + "', age=" + age + "}";
    }
}

public class task1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        List<Person> people = new ArrayList<>();

        System.out.print("Enter number of users (n): ");
        int n = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < n; i++) {
            System.out.println("\n--- User " + (i + 1) + " ---");
            System.out.print("Enter name: ");
            String name = scanner.nextLine().trim();

            System.out.print("Enter age: ");
            int age = Integer.parseInt(scanner.nextLine());

            Person newPerson = new Person(name, age);

            for (Person person : people) {
                if (person.equals(newPerson)) {
                    continue;
                } else {
                    people.add(newPerson);
                    break;
                }
            }
            if (!people.contains(newPerson)) {
                people.add(newPerson);
                System.out.println("The user is successfully added.");
            } else {
                System.out.println("User with name \"" + name + "\" already exists and won't be added!");
            }
        }

        // Принтиране на уникалните потребители
        System.out.println("\n===== Unique users =====");
        if (people.isEmpty()) {
            System.out.println("No added users");
        } else {
            for (Person p : people) {
                System.out.println(p);
            }
        }

        scanner.close();
    }
}
