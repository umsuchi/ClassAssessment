package ClassAssessment.Java;
import java.util.*;
public class ShoppingCart {
    double calculateTotal(double price1 , int quan1 , double price2 , int quan2){
        return ((price1*quan1) + (price2*quan2));
    }
    double calculateTotal(double price , int quan){return (price*quan);}
    public static void main(String[] args) {
        Scanner o = new Scanner(System.in);
        ShoppingCart obj = new ShoppingCart();
        System.out.print("Enter no of items : ");
        int n = o.nextInt();
        System.out.print("Cost per item : ");
        double p = o.nextDouble();
        System.out.println("Total cost for "+n+" items at "+p+" each is "+obj.calculateTotal(p, n));
        System.out.print("Enter no of items : ");
        int n1 = o.nextInt();
        System.out.print("Cost per item : ");
        double p1 = o.nextDouble();
        System.out.print("Enter no of items : ");
        int n2 = o.nextInt();
        System.out.print("Cost per item : ");
        double p2 = o.nextDouble();
        System.out.println("Total cost for "+n1+" items at "+p1+" and "+n2+" items at "+p2+" each is "+obj.calculateTotal(p1, n1, p2, n2));
    }
}
