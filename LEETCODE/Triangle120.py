class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(len(triangle)-2, -1, -1):  # for each row in triangle (skipping the last),
            for j in range(i+1):                  # loop through each element in the row
                triangle[i][j] += min(triangle[i+1][j],    # minimum sum from coordinate (x+1, y)
                                      triangle[i+1][j+1])  # minimum sum from coordinate (x+1, y+1)
        return triangle[0][0]
