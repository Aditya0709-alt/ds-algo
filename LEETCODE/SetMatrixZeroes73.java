/*
We use two sets to store the rows and columns which are having 0 as thier current element. 
We then iterate through the row and colun sets to make the coresponding rows and columns as zero

Time Complexity: O(m * n) where m = number of rows, n = number of columns
Space Complexity: O(1) i.e. in-place
*/


class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> rowSet = new HashSet<>();
        Set<Integer> colSet = new HashSet<>();

        
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0) {
                    rowSet.add(i);
                    colSet.add(j);
                }
            }
        }

        for(int a : rowSet) {
            for(int j = 0; j < matrix[0].length; j++) {
                matrix[a][j] = 0;
            }
        }

        for(int b : colSet) {
            for(int j = 0; j < matrix.length; j++) {
                matrix[j][b] = 0;
            }
        }
    }
    
    
}
