class CountPairs {
  
  static int countPairs(int [] a, int n, int k){
    Arrays.sort(a);
    int count = 0;
    for(int i = 0; i < n; i++){
      int low = i+1, high = n;
      while(low < high){
        int mid = (low+high)/2;
        if(a[mid] >= 2*k-a[i])
          high = mid;
        else 
          low = mid+1;
      count += n - high;
      }
      return count;
    }
  }
  public static void main(String [] args){
    int [] a = {2,3,4,1,6,5};
    int n = a.length;
    int k = 2;
    System.out.println(countPairs(a,n,k));
  }
}
