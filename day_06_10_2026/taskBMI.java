import java.util.Scanner;

class BMICalculator {

    // 2. printIntroduction() - explains what the program does
    public static void printIntroduction() {
        System.out.println("=== Body Mass Index (BMI) Calculator ===");
        System.out.println("This program calculates your Body Mass Index (BMI)");
        System.out.println("based on your height and weight.\n");
    }

    // 4. bmiFor() - calculates BMI using weight * 703 / (height * height)
    public static double bmiFor(double weight, double height) {
        return (weight * 703.0) / (height * height);
    }

    // 3. & 5. getBMI() - prompts for height and weight, returns bmiFor()
    public static double getBMI(Scanner scanner) {
        System.out.print("Enter height in inches (1 cm = 0.3937 inch): ");
        double height = scanner.nextDouble();

        System.out.print("Enter weight in pounds (1 kg = 2.2046 lb): ");
        double weight = scanner.nextDouble();

        return bmiFor(weight, height);
    }

    // 6. getStatus() - returns classification based on BMI
    public static String getStatus(double bmi) {
        if (bmi <= 18.5) {
            return "underweight";
        } else if (bmi <= 25.0) {
            return "normal";
        } else if (bmi <= 30.0) {
            return "overweight";
        } else {
            return "obese";
        }
    }

    // 7. reportResults() / ReportResults() - reports rounded BMI to 2 decimal
    // places
    public static void reportResults(int personNumber, double bmi, String status) {
        double roundedBMI = Math.round(bmi * 100.0) / 100.0;
        System.out.println("\nPerson #" + personNumber + " has BMI = " + roundedBMI + " (" + status + ")");
    }

    public static void ReportResults(int personNumber, double bmi, String status) {
        reportResults(personNumber, bmi, status);
    }

    // 8. main() - reads input, gets BMI, gets status, reports results
    public static void main(String[] args) {
        printIntroduction();

        Scanner scanner = new Scanner(System.in);

        double bmi = getBMI(scanner);
        String status = getStatus(bmi);
        reportResults(1, bmi, status);

        scanner.close();
    }
}