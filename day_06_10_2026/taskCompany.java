class Company {
    private String name;
    private String creationDate;
    private String bulstat;

    public Company() {
    }

    public Company(String name, String creationDate, String bulstat) {
        this.name = name;
        this.creationDate = creationDate;
        setBulstat(bulstat);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(String creationDate) {
        this.creationDate = creationDate;
    }

    public String getBulstat() {
        return bulstat;
    }

    // Проверка за дължина на string-а (length = 10)
    public void setBulstat(String bulstat) {
        if (bulstat != null && bulstat.length() == 10) {
            this.bulstat = bulstat;
        } else {
            System.out.println("Error: Bulstat must be exactly 10 characters long!");
        }
    }
}

class CompanyET extends Company {
    private String ownerName;
    private double initialCapital;
    private double actualCapital;

    public CompanyET() {
        super();
    }

    public CompanyET(String name, String creationDate, String bulstat,
            String ownerName, double initialCapital, double actualCapital) {
        super(name, creationDate, bulstat);
        this.ownerName = ownerName;
        this.initialCapital = initialCapital;
        this.actualCapital = actualCapital;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public double getInitialCapital() {
        return initialCapital;
    }

    public void setInitialCapital(double initialCapital) {
        this.initialCapital = initialCapital;
    }

    public double getActualCapital() {
        return actualCapital;
    }

    public void setActualCapital(double actualCapital) {
        this.actualCapital = actualCapital;
    }

    // Нестатичен метод, изчисляващ печалбата към днешна дата (актуален -
    // първоначален капитал)
    public double calculateProfit() {
        return actualCapital - initialCapital;
    }

    public double profit() {
        return calculateProfit();
    }

    public static void main(String[] args) {
        CompanyET et = new CompanyET(
                "Tech Consult",
                "15.03.2021",
                "1234567890",
                "Ivan Ivanov",
                1000.0,
                4500.0);

        System.out.println("Company name: " + et.getName());
        System.out.println("Creation date: " + et.getCreationDate());
        System.out.println("Bulstat: " + et.getBulstat());
        System.out.println("Owner name: " + et.getOwnerName());
        System.out.println("Initial capital: " + et.getInitialCapital());
        System.out.println("Actual capital: " + et.getActualCapital());
        System.out.println("Profit to date: " + et.calculateProfit());S
    }
}