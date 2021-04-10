import java.io.*;
import java.util.*;
import java.math.BigInteger; 

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String n1 = scanner.nextLine();
        String n2 = scanner.nextLine();
        BigInteger a = new BigInteger(n1);
        BigInteger b = new BigInteger(n2);

        BigInteger sum = a.add(b);
        BigInteger prod = a.multiply(b);

        System.out.println(sum.toString());
        System.out.println(prod.toString());

        scanner.close();
    }
}
