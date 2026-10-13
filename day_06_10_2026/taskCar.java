// 1. Клас Car
class Car {
    private String brand;
    private String model;
    private String color;
    private int power;
    private String engineType;
    private String gearbox;
    private int year;

    // Конструктор без параметри
    public Car() {
    }

    // Конструктор с параметри
    public Car(String brand, String model, String color, int power, String engineType, String gearbox, int year) {
        this.brand = brand;
        this.model = model;
        this.color = color;
        this.power = power;
        this.engineType = engineType;
        this.gearbox = gearbox;
        this.year = year;
    }

    // Get и Set методи
    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public String getEngineType() {
        return engineType;
    }

    public void setEngineType(String engineType) {
        this.engineType = engineType;
    }

    public String getGearbox() {
        return gearbox;
    }

    public void setGearbox(String gearbox) {
        this.gearbox = gearbox;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    // 2. Метод, който филтрира по първа буква на марката
    public static Car[] filterByLetter(Car[] cars, char letter) {
        if (cars == null) return new Car[0];

        char upperLetter = Character.toUpperCase(letter);
        int count = 0;
        for (int i = 0; i < cars.length; i++) {
            if (cars[i] != null && cars[i].getBrand() != null && !cars[i].getBrand().isEmpty()) {
                if (Character.toUpperCase(cars[i].getBrand().charAt(0)) == upperLetter) {
                    count++;
                }
            }
        }

        Car[] result = new Car[count];
        int index = 0;
        for (int i = 0; i < cars.length; i++) {
            if (cars[i] != null && cars[i].getBrand() != null && !cars[i].getBrand().isEmpty()) {
                if (Character.toUpperCase(cars[i].getBrand().charAt(0)) == upperLetter) {
                    result[index++] = cars[i];
                }
            }
        }
        return result;
    }

    // 3. Метод за сортиране по марка (ascending = true за възходящ, false за низходящ)
    public static Car[] sortByBrand(Car[] cars, boolean ascending) {
        if (cars == null) return new Car[0];

        Car[] sorted = cars.clone();
        for (int i = 0; i < sorted.length - 1; i++) {
            for (int j = 0; j < sorted.length - i - 1; j++) {
                int cmp = sorted[j].getBrand().compareToIgnoreCase(sorted[j + 1].getBrand());
                boolean shouldSwap = ascending ? (cmp > 0) : (cmp < 0);
                if (shouldSwap) {
                    Car temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }
        return sorted;
    }

    // 4. Метод, който премахва повтарящите се коли
    public static Car[] removeDuplicates(Car[] cars) {
        if (cars == null) return new Car[0];

        Car[] temp = new Car[cars.length];
        int uniqueCount = 0;

        for (int i = 0; i < cars.length; i++) {
            if (cars[i] == null) continue;

            boolean isDuplicate = false;
            for (int j = 0; j < uniqueCount; j++) {
                if (cars[i].equals(temp[j])) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                temp[uniqueCount++] = cars[i];
            }
        }

        Car[] result = new Car[uniqueCount];
        for (int i = 0; i < uniqueCount; i++) {
            result[i] = temp[i];
        }
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Car other = (Car) obj;
        return power == other.power &&
               year == other.year &&
               brand.equalsIgnoreCase(other.brand) &&
               model.equalsIgnoreCase(other.model) &&
               color.equalsIgnoreCase(other.color) &&
               engineType.equalsIgnoreCase(other.engineType) &&
               gearbox.equalsIgnoreCase(other.gearbox);
    }

    @Override
    public String toString() {
        return brand + " " + model + " (" + year + ", " + color + ", " + power + " hp, " + engineType + ", " + gearbox + ")";
    }

    // Позволява стартиране и чрез java Car
    public static void main(String[] args) {
        Test.main(args);
    }
}

// 5. Клас Test с main метод според условието
class Test {
    public static void printCars(Car[] cars) {
        for (int i = 0; i < cars.length; i++) {
            System.out.println("  " + (i + 1) + ". " + cars[i]);
        }
    }

    public static void main(String[] args) {
        Car c1 = new Car("BMW", "320d", "Black", 190, "Diesel", "Automatic", 2018);
        Car c2 = new Car("Audi", "A4", "White", 150, "Petrol", "Manual", 2016);
        Car c3 = new Car("Mercedes", "C220", "Silver", 170, "Diesel", "Automatic", 2019);
        Car c4 = new Car("BMW", "M3", "Blue", 450, "Petrol", "Automatic", 2021);
        Car c5 = new Car("Audi", "A4", "White", 150, "Petrol", "Manual", 2016); // Дубликат на c2

        Car[] cars = { c1, c2, c3, c4, c5 };

        System.out.println("=== All initial cars ===");
        printCars(cars);

        // 2. Тест: Филтриране по буква 'B'
        System.out.println("\n=== 2. Cars starting with brand letter 'B' ===");
        Car[] filteredByB = Car.filterByLetter(cars, 'B');
        printCars(filteredByB);

        // 3. Тест: Сортиране по възходящ ред (A-Z)
        System.out.println("\n=== 3. Sorted by brand ascending (A-Z) ===");
        Car[] sortedAsc = Car.sortByBrand(cars, true);
        printCars(sortedAsc);

        // 3. Тест: Сортиране по низходящ ред (Z-A)
        System.out.println("\n=== 3. Sorted by brand descending (Z-A) ===");
        Car[] sortedDesc = Car.sortByBrand(cars, false);
        printCars(sortedDesc);

        // 4. Тест: Премахване на дублиращи се коли
        System.out.println("\n=== 4. Cars after removing duplicates ===");
        Car[] uniqueCars = Car.removeDuplicates(cars);
        printCars(uniqueCars);
    }
}