import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int i = scan.nextInt();
        scan.nextLine(); // This line you have to add (It consumes the \n character)
        double d = scan.nextDouble();
        scan.nextLine(); // This line you have to add (It consumes the \n character)
        String s = scan.nextLine();      
        scan.close();
        
        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    
    }
}