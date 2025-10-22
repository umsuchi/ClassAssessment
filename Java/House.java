package ClassAssessment.Java;
import java.util.*;

class House{
    private String address;
    private int numofRooms;
    private double area;
    public void setaddress(String add){address = add;}
    public void setnumofRooms(int room){numofRooms = room;}
    public void setarea(double area){this.area = area;}
    public String getaddress(){return address;}
    public int getnoofRooms(){return numofRooms;}
    public double getarea(){return area;}
    public double calculatePrice(double price){
        return this.area*price;
    }
    public static void main(String[] args) {
        House obj = new House();
        try (Scanner o = new Scanner(System.in)){
            System.out.print("Enter Address : ");
            String add = o.nextLine();
            obj.setaddress(add);
            
            System.out.print("Enter NO of Rooms : ");
            int room = o.nextInt();
            obj.setnumofRooms(room);
            
            System.out.print("Measurement of Area : ");
            double area = o.nextDouble();
            obj.setarea(area);
            
            System.out.print("Enter Price per square meter : ");
            double price = o.nextDouble();
            System.out.println("Address : "+obj.getaddress()+"\nNO of Rooms : "+obj.getnoofRooms()+"\nArea : "+obj.getarea()+"\nPrice of the House : "+obj.calculatePrice(price));
    
        }
    }
}