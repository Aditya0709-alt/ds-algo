
/*
wt[] = {1,3,4,5}; val[] = {1,4,5,7}; W = 7;
The 0-1 knapsack problem is recursive as we have a choice to include a particular item in the sack. 
*/

// Recursive approach
static int knapsack(int [] wt, int [] val, int W, int n){
        if(n == 0 || W == 0){
            return 0;
        }
        
        if(wt[n-1] <= W){
            return max((val[n-1] + knapsack(wt,val,W - wt[n-1], n-1)), knapsack(wt,val,W,n-1));
        }
        
        
            return knapsack(wt,val,W,n-1);
        
    }
