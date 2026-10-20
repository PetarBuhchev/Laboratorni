import java.util.ArrayList;

interface Workable {
    void performDuty();
}

interface EmployeeManagement {
    void addEmployee(Employee employee);

    void listEmployees();
}

abstract class Employee implements Workable {

    protected String name;
    protected double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public abstract String getPosition();

    @Override
    public String toString() {
        return getPosition() +
                " | Name: " + name +
                " | Salary: " + salary;
    }
}

class Waiter extends Employee {

    public Waiter(String name, double salary) {
        super(name, salary);
    }

    @Override
    public void performDuty() {
        System.out.println(name + " serves clients.");
    }

    @Override
    public String getPosition() {
        return "Waiter";
    }
}

class Cook extends Employee {

    public Cook(String name, double salary) {
        super(name, salary);
    }

    @Override
    public void performDuty() {
        System.out.println(name + " cook meals.");
    }

    @Override
    public String getPosition() {
        return "Cook";
    }
}

class Manager extends Employee {

    public Manager(String name, double salary) {
        super(name, salary);
    }

    @Override
    public void performDuty() {
        System.out.println(name + " manages the restaurant.");
    }

    @Override
    public String getPosition() {
        return "Manager";
    }
}

class RestaurantStaffManager implements EmployeeManagement {

    private ArrayList<Employee> employees = new ArrayList<>();

    @Override
    public void addEmployee(Employee employee) {
        employees.add(employee);
        System.out.println(employee.getName() + " is added to the system.");
    }

    @Override
    public void listEmployees() {
        System.out.println("\n------ STAFF ------");

        for (Employee employee : employees) {
            System.out.println(employee);
        }
    }

    public ArrayList<Employee> getEmployees() {
        return employees;
    }
}

public class Task {

    public static void main(String[] args) {

        RestaurantStaffManager staffManager = new RestaurantStaffManager();

        staffManager.addEmployee(new Waiter("Ivan", 1600));
        staffManager.addEmployee(new Cook("Petar", 2200));
        staffManager.addEmployee(new Manager("Mariya", 3000));

        staffManager.listEmployees();

        System.out.println("\n------ OBLIGATIONS ------");

        for (Employee employee : staffManager.getEmployees()) {
            employee.performDuty();
        }
    }
}