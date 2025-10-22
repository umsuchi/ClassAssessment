package ClassAssessment.Java;
import java.util.*;
import java.io.*;
class AreaCalculator{
    double calculateArea(double radius){
        return (Math.PI * radius * radius);
    }
    double calculateArea(double length , double width){
        return (length * width);
    }
    int calculateArea(int side){
        return (side * side);
    }
    public static void main(String [] args){
        try (Scanner o = new Scanner(new File("input.txt"))){
            System.out.println("Radius ,, Length ,, Width ,, Side");
            double rad = o.nextDouble();
            double len = o.nextDouble();
            double wid = o.nextDouble();
            int si = o.nextInt();
            AreaCalculator obj = new AreaCalculator();
            System.out.println("Area of circle with radius "+rad+" is "+obj.calculateArea(rad));
            System.out.println("Area of rectangle with length "+len+"and width "+wid+" is "+obj.calculateArea(len , wid));
            System.out.println("Area of square with side "+si+" is "+obj.calculateArea(si));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}