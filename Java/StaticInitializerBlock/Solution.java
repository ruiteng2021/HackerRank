import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static Boolean flag = true;
    public static int B = 0;
    public static int H = 0;
    static {
        String error = "java.lang.Exception: Breadth and height must be positive";
        Scanner sc = new Scanner(System.in);
        B = sc.nextInt();
        H = sc.nextInt();
        int result = B*H;
        if(B <= 0 || H <= 0 ){
            System.out.println(error);
            flag = false;
        }           
    }
    
    public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
	}//end of main

}//end of class
    
    
    
/*
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int B = sc.nextInt();
        int H = sc.nextInt();
        int flag = B*H;

        if(flag > 0)
            System.out.print(flag);
        else
            System.out.print(error);
        
        }//end of main

}//end of class
*/