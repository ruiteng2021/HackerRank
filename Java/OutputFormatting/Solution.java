import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("================================");
        for(int i=0;i<3;i++)
        {
            String s1=sc.nextLine();
            String array[] = s1.split(" ");
            //int x = Integer.parseInt(array[1]);
            System.out.printf("%-15s%03d\n", array[0], Integer.parseInt(array[1]));
        }
        System.out.println("================================");
    }
}