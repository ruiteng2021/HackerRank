import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.stream.Collectors;

public class Solution {

    // Complete the rotLeft function below.
    static int[] rotLeft(int[] a, int d) {
        
        int [] result = new int[a.length];        
        List<Integer> temp =  Arrays.stream(a).boxed().collect(Collectors.toList());
        List<Integer> temp1 = new ArrayList<Integer>();
        temp1.addAll(temp.subList(0,d));

        List<Integer> temp2 = new ArrayList<Integer>();
        temp2.addAll(temp.subList(d, a.length));

        System.out.println(temp1);
        System.out.println(temp2);

        temp.clear();
        temp.addAll(temp2);
        temp.addAll(temp1);
        System.out.println(temp);
        
        result = temp.stream().mapToInt(Integer::intValue).toArray();
        System.out.println(result);

        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aItems[i]);
            a[i] = aItem;
        }

        int[] result = rotLeft(a, d);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
