import java.util.*;
public class Main
{
    
        static int[] kWeakest(int[][] mat, int k) {
        int[] val = new int[mat.length];
        int[] ind = new int[mat.length];
        for (int i=0; i<mat.length;i++) {
            int sum=0;
            for (int j=0;j<mat[i].length;j++) {
                sum+=mat[i][j];
            }
            ind[i] = i;
            val[i]=sum;
        }
        for (int n=1;n<val.length;n++) {
            int key = val[n];
            int ind_key = ind[n];
            int m=n-1;
            while (m>=0 && val[m]>key) {
                val[m+1] = val[m];
                ind[m+1] = ind[m];
                m=m-1;
            }
            val[m+1]=key;
            ind[m+1]=ind_key;
        }
        int[] f = Arrays.copyOfRange(ind,0,k);
        return f;
    }
    
	public static void main(String[] args) {
		int [][] arr = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
		int k = 3;
		
		int [] res = kWeakest(arr,k);
		for(int i = 0; i < res.length; i++){
		    System.out.print(res[i]+ " ");
		}
	}
}





