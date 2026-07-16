import java.util.*;

public class Main {

public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    String s = sc.next();

    int L = s.length();

    for(int ctr=(1<<L)-1;ctr>=0;ctr--){

        StringBuilder combi=new StringBuilder();

        for(int sh=0;sh<L;sh++){

            if((ctr&(1<<sh))!=0){

                combi.append(s.charAt(sh));
            }
        }

        System.out.println(combi);
    }
  }
}
