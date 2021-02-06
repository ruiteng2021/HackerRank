import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inputLine;
        int n = 1;
        while(sc.hasNext()) {
            inputLine = sc.nextLine();
            System.out.printf("%d %s\n", n, inputLine);
            //parse inputLine however you want, and add to your vector
            n++;
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}