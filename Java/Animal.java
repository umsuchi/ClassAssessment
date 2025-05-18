package ClassAssessment.Java;

class Animal {
    String name;
    int age;

    Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    void makeSound() {
        System.out.println("The animal makes a sound.");
    }
    void eat() {
        System.out.println("The animal is eating.");
    }
    void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

class Dog extends Animal {
    String breed;
    Dog(String name, int age, String breed) {
        super(name, age);
        this.breed = breed;
    }
    @Override
    void makeSound() {
        System.out.println("The dog barks.");
    }
    void fetch() {
        System.out.println("The dog is fetching the ball.");
    }
    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Breed: " + breed);
    }
}

class Cat extends Animal {
    String color;
    Cat(String name, int age, String color) {
        super(name, age);
        this.color = color;
    }
    @Override
    void makeSound() {
        System.out.println("The cat meows.");
    }
    void scratch() {
        System.out.println("The cat is scratching the cloth.");
    }
    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Color: " + color);
    }
}
class Zoo {
    public static void main(String[] args) {
        Animal animal = new Animal("GenericAnimal", 5);
        Dog dog = new Dog("Rex", 3, "Labrador");
        Cat cat = new Cat("Mittens", 2, "White");
        animal.makeSound();
        animal.eat();
        animal.displayInfo();
        dog.makeSound();
        dog.fetch();
        dog.displayInfo();
        cat.makeSound();
        cat.scratch();
        cat.displayInfo();
    }
}
