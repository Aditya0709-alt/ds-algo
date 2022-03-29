
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
// Bottom-up approach
// It is one of the most preferable methods in dynamic programming. 
// It is faster than the memoization method as it doesn't involve any recursive calls. 
// In this method, we have an array/matrix and we start from the first cell and move down filling entries in each cell one by one.

static int max(int a, int b){
        return (a > b) ? a : b;
    }
    
	static int knapsack(int [] wt, int [] val, int W, int n){
	    int i, j;
	    int [][] t = new int[n+1][W+1];
	    
        for(i = 0; i < n+1; i++){
            for(j = 0; j < W+1; j++){
                if(i ==0 || j == 0){
                    t[i][j] = 0;
                }
                else if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
