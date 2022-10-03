import java.util.*;
public class PiggyBank {
    static int sum = 0;
    static void popping(List<Integer> list){
        int currSum = 0;
        int index = 0;
        if(list.size()==1){
            sum = list.get(index);
        }
        else if(list.size()==2){
            if(list.get(0)>list.get(1)){
                sum = list.get(1)*list.get(0);
                index = 1;
            }
            else{
                sum = list.get(0)*list.get(1);
                index = 0;
            }
            
        }
        else{

            for (int i = 0; i < list.size(); i++) {
                if(i==0){
                    currSum = list.get(i)*list.get(i+1);
                }
                else if(i==list.size()-1){
                    currSum = list.get(i-1)*list.get(i);
                }
                else{
                    currSum = list.get(i-1)*list.get(i)*list.get(i+1);
                }
                if(sum<currSum){
                    index = i;
                    sum = currSum;
                }
            }
        }
        
        list.remove(index);
        System.out.println(list);

    } 
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        int globalSum = 0;
        list.add(3);
        list.add(5);
        list.add(6);
        list.add(15);
        // 3 5 15 6
        while(!list.isEmpty()){
            popping(list);
            globalSum+=sum;
            sum = 0;
        }
        System.out.println(globalSum);
    
    }
}
