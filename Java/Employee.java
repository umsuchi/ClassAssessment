package ClassAssessment.Java;

class Employee {
    String name, address, jobTitle;
    double salary;
    Employee(String name, String address, double salary, String jobTitle) {
        this.name = name;
        this.address = address;
        this.salary = salary;
        this.jobTitle = jobTitle;
    }
    double calculateBonus() {
        return salary * 0.05;
    }
    void generateReport() {
        System.out.println("Basic performance report.");
    }
    void displayInfo() {
        System.out.println("Name: " + name + ", Address: " + address + ", Salary: " + salary + ", Job Title: " + jobTitle);
    }
}
class Manager extends Employee {
    Manager(String name, String address, double salary) {
        super(name, address, salary, "Manager");
    }
    @Override
    double calculateBonus() {
        return salary * 0.10;
    }
    void manageProject() {
        System.out.println("Managing the project.");
    }
}
class Developer extends Employee {
    Developer(String name, String address, double salary) {
        super(name, address, salary, "Developer");
    }
    @Override
    double calculateBonus() {
        return salary * 0.07;
    }
    void writeCode() {
        System.out.println("Writing code.");
    }
}
class Programmer extends Employee {
    Programmer(String name, String address, double salary) {
        super(name, address, salary, "Programmer");
    }
    @Override
    double calculateBonus() {
        return salary * 0.06;
    }
    void debugCode() { 
        System.out.println("Debugging code.");
    }
}
class Company {
    public static void main(String[] args) {
        Manager m = new Manager("Rowaha", "Dhaka", 80000.00);
        Developer d = new Developer("Khawla", "Borishal", 75500.00);
        Programmer p = new Programmer("Hamdi", "Chattogram", 60000.00);
        m.displayInfo();
        System.out.println("Bonus: " + m.calculateBonus());
        m.manageProject();
        d.displayInfo();
        System.out.println("Bonus: " + d.calculateBonus());
        d.writeCode();
        p.displayInfo();
        System.out.println("Bonus: " + p.calculateBonus());
        p.debugCode();
    }
}