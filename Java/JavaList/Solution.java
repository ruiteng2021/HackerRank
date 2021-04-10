import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner input = new Scanner(System.in);
        int x = input.nextInt();
        input.nextLine();
        String y = input.nextLine();
        String[] inputS = y.split(" "); 
        //StringBuffer inputI = new StringBuffer();
        ArrayList<String> inputII = new ArrayList<>();
        for (String item : inputS){
            //inputI.append(item);
            inputII.add(item);
        }
        int q = input.nextInt();
        input.nextLine();
        for (int i=0; i < q; i++){
            String command = input.nextLine();
            String pos = input.nextLine();
            String[] positions = pos.split(" "); 
            if (command.equals("Insert")){
                //inputI.insert(Integer.parseInt(positions[0]), positions[1]);
                inputII.add(Integer.parseInt(positions[0]), positions[1]);
            }
            if (command.equals("Delete")){
                inputII.remove(Integer.parseInt(positions[0]));
            }
        }
        for (String item : inputII)
            System.out.print(item + " ");
    }
}