public class Search2D74
{
    
    static boolean binarySearch(int [] arr, int k){
        int l = 0, r = arr.length-1;
        
        while(r >= l){
            int mid = l + (r-l)/2;
            if(arr[mid] == k){
                return true;
            }
            else if(k < arr[mid]){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return false;
    }
    
    static boolean searchMatrix(int [][] matrix, int K){
        int m = matrix.length, n = matrix[0].length;
        int l = 0, r = m - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(K >= matrix[mid][0] && K <= matrix[mid][n-1]){
                return binarySearch(matrix[mid],K);
            }
            else if( K < matrix[mid][0]){
                r = mid-1; 
            }
            else {
                l = mid+1;
            }
        }
        return false;
    }
	public static void main(String[] args) {
		int matrix[][] = {
                {1,3,5,7},
                {10,11,16,20},
                {23,30,34,50}
                     };
        
        if(searchMatrix(matrix,16)){
          System.out.println("Element found");
        } else {
          System.out.println("Element not found");
        }   
	  }
}
