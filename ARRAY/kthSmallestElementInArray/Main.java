import java.util.*;

public class Main {

	public static void main(String[] args)
	{
		int [] arr = {-12,25,644,-56,2,67};
		
		PriorityQueue<Integer> pq
			= new PriorityQueue<Integer>(
				new Comparator<Integer>() {
					public int compare(Integer a, Integer b)
					{
						if (a < b)
							return 1;
						if (a > b)
							return -1;
						else
						    return 0;
					}
				});

		for(int i: arr){
		    pq.add(i);
		    
		    while(!pq.isEmpty() && pq.size() > 3){
		    pQueue.poll();
		    }
	    }
	    System.out.println(pq.peek());
	}
}

