import java.util.*;
public class ShakuntalaDevi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the string");
        String x = sc.next();

        int man = 0;
        int woman = 0;
        int ans = -1;
        boolean lastMale = false;
        for (int i = 0; i < x.length(); i++) {
            if(x.charAt(i)=='w'){
                if(lastMale){
                    woman=0;
                }
                woman++;
                lastMale = false;
            }
            if(x.charAt(i)=='m'){
                man++;
                if(woman==man){
                    ans = Math.max(ans, 2*woman);
                    
                }
                lastMale = true;
            } 
                
        }
        System.out.println("Answer :- " + ans);
    }
}
