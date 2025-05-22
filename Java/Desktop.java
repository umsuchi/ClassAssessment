package ClassAssessment.Java;
import java.util.*;

class Desktop {
    private String brand;
    private String processor;
    private int ramSize;
    public void setbrand(String b){brand = b;}
    public void setprocessor(String pro){processor = pro;}
    public void setramSize(int ram){ramSize = ram;}
    public String getbrand(){return brand;}
    public String getprocessor(){return processor;}
    public int getramSize(){return ramSize;}
    public int upgradeRam(int ram){
        if(ram > 0) this.ramSize += ram ;
        return ramSize; 
    }
    public static void main(String[] args) {
        Desktop obj = new Desktop();
        Scanner o = new Scanner(System.in);
        System.out.print("Enter the brand name : ");
        String b = o.nextLine();
        obj.setbrand(b);
        System.out.print("Enter the processor name : ");
        String pro = o.nextLine();
        obj.setprocessor(pro);
        System.out.print("Enter ram size : ");
        int r = o.nextInt();
        obj.setramSize(r);
        System.out.print("Enter additional ram size : ");
        int ram = o.nextInt();
        System.out.println("Brand : "+obj.getbrand()+"\nProcessor : "+obj.getprocessor()+"\nRam : "+obj.getramSize()+"\nAfter adding ram : "+obj.upgradeRam(ram));    
    }
    
}
