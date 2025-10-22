package ClassAssessment.Java;
import java.util.*;
class CircleGeometry {
    void compute(double rad){
        System.out.println("For radius "+rad+" , Area = "+Math.PI*rad*rad+" , Circumference = "+2*Math.PI*rad);
    }
    void compute(int rad){
        System.out.println("For radius "+rad+" , Area = "+Math.PI*rad*rad+" , Circumference = "+2*Math.PI*rad);
    }
    public static void main(String[] args) {
        try (Scanner o = new Scanner(System.in)){
            CircleGeometry obj = new CircleGeometry();
            System.out.print("Enter radius : ");
            double r1 = o.nextDouble();
            obj.compute(r1);
            System.out.print("Enter radius : ");
            double r2 = o.nextInt();
            obj.compute(r2);
        }
    }
}
