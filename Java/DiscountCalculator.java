package ClassAssessment.Java;
import java.util.*;
class DiscountCalculator {
    double calculateDiscount(double price , double disPer){
        return (price * disPer);
    }
    int calculateDiscount(int price , int disPer){
        return (price * disPer) / 100 ;
    }
    public static void main(String[] args) {
        try (Scanner o = new Scanner(System.in)){
            DiscountCalculator obj = new DiscountCalculator();
            System.out.print("Enter Price : ");
            double p1 = o.nextDouble();
            
            System.out.print("Enter Discount : ");
            double d1 = o.nextDouble();
            
            System.out.println("Discount on product with price : "+p1+" and "+d1+"% is "+obj.calculateDiscount(p1 , d1));
            System.out.print("Enter Price : ");
            
            int p2 = o.nextInt();
            System.out.print("Enter Discount : ");
            
            int d2 = o.nextInt();
            System.out.println("Discount on product with price : "+p2+" and "+d2+"% is "+obj.calculateDiscount(p2 , d2));
        }
    }
}
