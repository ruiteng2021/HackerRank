import java.util.*;
import java.io.*;

class Solution{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            int out = a;
            for (int x = 0; x < n; x++){
                int cal = (int)(Math.pow(2,x)*b);
                out = out + cal;
                System.out.print(out + " ");
            }
            System.out.println();
        }
        in.close();
    }
}

/*
2
5 3 5
0 2 10
*/