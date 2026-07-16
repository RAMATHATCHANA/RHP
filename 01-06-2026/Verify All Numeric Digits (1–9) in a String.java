import java.util.*;

public class Main {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        String str = sc.next();

        int flag = 0;

        for(int i=0;i<str.length();i++){

            char ch=str.charAt(i);

            if(ch>='1' && ch<='9')
                flag |= (1<<(ch-'1'));
        }

        if(flag==(1<<9)-1)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
