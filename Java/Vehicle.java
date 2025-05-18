package ClassAssessment.Java;

class Vehicle {
    int speed = 50;
    public Vehicle(String color) {
        System.out.println("Vehicle is created with color:" + color);
    }
    public void display() {
        System.out.println("The vehicle Speed is: " + speed);
    }
}
class Car extends Vehicle {
    int speed = 100;
    Car(){
        super("Red");
        System.out.println("Car is Created\n");
    }
    public void display(){
        super.display();
        System.out.println("Vehicle Speed is:"+super.speed);
        System.out.println("Car Speed is: "+speed);
    }
    public static void main(String[] args) {
        Car c1 = new Car();
        c1.display();
        c1 = new Car();
        Vehicle v1 = new Vehicle(" Blue");
    }
}
