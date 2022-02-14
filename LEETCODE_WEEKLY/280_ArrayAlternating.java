class Solution {
public int minimumOperations(int[] nums) {
    if(nums.length < 2) {
        return 0;
    }

	//Storing frequencies at odd and even indices
    Map<Integer,Integer> oddFreq = new HashMap();
    int oddLen = 0;
    Map<Integer,Integer> evenFreq = new HashMap();
    int evenLen = 0;
    
    for(int i=0; i<nums.length; i++) {
        if(i%2 == 0) {
            evenFreq.put(nums[i], evenFreq.getOrDefault(nums[i],0)+1);
            evenLen++;
        }
        else {
            oddFreq.put(nums[i], oddFreq.getOrDefault(nums[i],0)+1);
            oddLen++;
        }
    }
    
	//The most frequent elements at odd and even indices can be equal, 
	//hence we may need to know second most frequent in each case, 
	//Therefore creating PriorityQueues using the maps just created
    PriorityQueue<int[]> sortedEvenFreq = new PriorityQueue<>((a,b) -> Integer.compare(b[1],a[1]));
    for(Map.Entry<Integer,Integer> entry : evenFreq.entrySet()) {
        int[] curr = new int[]{entry.getKey(), entry.getValue()};
        sortedEvenFreq.add(curr);
    }
    PriorityQueue<int[]> sortedOddFreq = new PriorityQueue<>((a,b) -> Integer.compare(b[1],a[1]));
    for(Map.Entry<Integer,Integer> entry : oddFreq.entrySet()) {
        int[] curr = new int[]{entry.getKey(), entry.getValue()};
        sortedOddFreq.add(curr);
    }
    
    
    int[] currEven = sortedEvenFreq.poll();
    int[] currOdd = sortedOddFreq.poll();
    
    System.out.println(currEven[0]);
    System.out.println(currOdd[0]);

	//if most freq elements equal, then we need to choose which one to change
    if(currEven[0] == currOdd[0]) {
		//how populous the elements are on respective(odd or even) locations (even->2/3, odd 2/2, Then odd slack is less(0<1))
        int evenSlack = evenLen - currEven[1];
        int oddSlack = oddLen - currOdd[1];
		//if even is more populous, change odd
        if(evenSlack <= oddSlack) {
            if(!sortedOddFreq.isEmpty()) {
                currOdd = sortedOddFreq.poll();
            }
            else {
                currOdd[1] = 0;
            }
        }
        else {
            if(!sortedEvenFreq.isEmpty()) {
              currEven = sortedEvenFreq.poll();  
            }
            else {
                currEven[1] = 0;
            }
        }
    }

    return (evenLen-currEven[1])+(oddLen-currOdd[1]);
}
}
