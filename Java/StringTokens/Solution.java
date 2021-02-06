import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        //The + after treats consecutive delimiter chars as one
        String[] parts = s.trim().split("[ !,?._'@]+"); 
        if (parts.length == 1){
            if (parts[0].isEmpty())
                System.out.println("0");
            else
            {
                System.out.println(parts.length);
                System.out.println(parts[0]);
            }
        }
        else{
            System.out.println(parts.length);
            for (String item : parts){
                System.out.println(item);
            }
        }
            
        
        scan.close();
    }
}
/*
           YES      leading spaces        are valid,    problemsetters are         evillllll
                   

,_! ! _@?'  !?_,'! '_'_@.... ''?. ?_ !?. ..!'!?@,?@',?_@'!, !!?_,@?,'@@',, !.? @@@@!!?' _, @???_,@ !_@!'!!!__!??'!. _. ,@! !.?'@,' '_!@@,'?' '?' ''_? '!!'?_?,._!..@_,_', ',',, !!__!_@,.! '?...  ?_? ._ ?' _! '?_..,,''.'@'??.??' @'.?' ?'_.'.'_ .'??@',_@_ , ?! , ._ . ',_'@..' ?,?,!_'',',,,?,..',.?,?_',..@?.,_ .@_?_ ,',.?_!'.??'_@__!!!'._!!__'? .?,._'', @@?!@ '?_ .@  .!!!' .'.', _!''!_@.@..@',@? @?. .@'.,@ , !'! @,@.@. ?,'_!,_'_,'! @_,_@._'?'',!_@ ,'?.@ _!__@'. '?_, ?@_,,.,.@',@!!!@ !?!@ '@_'_ _'  @_? ,_. .@@@ '.  '!@  ._ ,__!__', '._?.,,, ,!.,!?? ??. ?@_  ,@'_@'!.,@@. @@,, ?_??!' !,@'?@!!@@'_ ?'@!.@', !?.'@' _'! @ ?.,., ?' ''@ ?_ __! ! '! . ,.@,'?.?__'__@..@'!@.@ _  .!! !?_ _.?,  ''_._! ? !,_ ,, ,@!?@,@?,. _@ @_'?!._,'_?!,??.?@,.!!' .!..',._'?  '_,'?@ _!.,_,.!?_ ?,,'@!!?@ @@!@.?_'!_.?!@ ??!' ,,,.,!_?.?.,!_ _ _.,?!_.'_ ,@'? !_.?@!',.?_@ _? ? ,@!', .,??!@??? @,!_.@ !. ''!,'?  ?,!'_.,@,@!_@ ''_._@_!@.!'@ ?@!@!,_@@ . @@_.@_??!!!@, ??'!., _ !'@'_@?_.!, ''?? ..''.,,.?@@??'.,_?'?'.' '' @,?'''@@.

                a                    

*/