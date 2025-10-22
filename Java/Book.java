package ClassAssessment.Java;
import java.util.*;

public class Book {
    private String title;
    private String author;
    private double price;
    public void settitle(String name){title = name;}
    public void setauthor(String writer){author = writer;}
    public void setprice(double pri){price = pri;}
    public String gettitle(){return title;}
    public String getauthor(){return author;}
    public double getprice(){return price;}
    public double applyDiscount(double dis){
        if(dis > 0 && dis <= 100) this.price = this.price - (this.price*(dis/100));
        return price;
    }
    public static void main(String[] args) {
        Book obj = new Book();
        try (Scanner o = new Scanner(System.in)){
            System.out.print("Enter Book name : ");
            String name = o.nextLine();
            obj.settitle(name);
            
            System.out.print("Enter Author name : ");
            String writer = o.nextLine();
            obj.setauthor(writer);
            
            System.out.print("Enter Price : ");
            double price = o.nextDouble();
            obj.setprice(price);
            
            System.out.print("Enter the percentage of Discount : ");
            double dis = o.nextDouble();
            System.out.println("Book name : "+obj.gettitle()+"\nAuthor : "
            +obj.getauthor()+"\nPrice : "+obj.getprice()+"\nAfter calculatin Discount Price : "
            +obj.applyDiscount(dis));
        }
        
    }
}
