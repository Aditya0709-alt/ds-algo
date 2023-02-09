## Recursion Practice

### Printing Subsequences

This includes contiguous and non-contiguous subsequences. 


```
import java.util.*;

public class Main {
    
    public static void printSubsquence(int [] arr, int index, ArrayList<Integer> path){
        
        if (index >= arr.length){
            if (path.size() > 0){
                System.out.print(path + " ");
            }
        } else {
            // pick the current index
            printSubsquence(arr, index + 1, path);
            
            path.add(arr[index]);
            
            // don't pick the current index
            printSubsquence(arr, index+ 1, path);
            
            path.remove(path.size() - 1);
        }
        return;
    }
    
    public static void main(String [] args){
        int [] arr = {1,2,3};
        
        ArrayList<Integer> path = new ArrayList<Integer>();
        
        printSubsquence(arr, 0, path);
    }
}
```
