package ClassAssessment.Java;

class Person {
    String name;
    int age;
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    void speak() {
        System.out.println("The person is speaking");
    }
    void displayDetails() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}
class Student extends Person {
    int rollNo;
    Student(String name, int age, int rollNo) {
        super(name, age);
        this.rollNo = rollNo;
    }
    @Override
    void speak() {
        System.out.println("The student is asking a question");
    }
    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Roll No: " + rollNo);
    }
}
class Teacher extends Person {
    String subject;
    Teacher(String name, int age, String subject) {
        super(name, age);
        this.subject = subject;
    }
    @Override
    void speak() {
        System.out.println("The teacher is giving a lecture");
    }
    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Subject: " + subject);
    }
}
class School {
    public static void main(String[] args) {
        Student student = new Student("Zigar", 20, 101);
        Teacher teacher = new Teacher("Ms. Aodhora", 28, "OOP");
        student.speak();
        student.displayDetails();
        teacher.speak();
        teacher.displayDetails();
    }
}    

