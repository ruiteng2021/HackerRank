import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        char[] B = new char[A.length()];
        for (int i = 0; i < A.length(); i++){
            B[A.length() - 1 - i] = A.charAt(i);
        }
        String C = new String(B);
        System.out.println(C);
        if (C.equals(A))
            System.out.println("Yes");
        else
            System.out.println("No");
        
    }
}
