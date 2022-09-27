#Time Complexity: O(N)

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        N = len(dominoes)
        INF = 10 ** 20
        
        
        def closest(dominoes, direction):
            right = [INF] * N
            for i in range(N):
                if dominoes[i] == direction:
                    right[i] = 0
                elif dominoes[i] == ".":
                    if i - 1 >= 0:
                        right[i] = right[i-1] + 1
                else:
                    right[i] = INF
            return right
        
        right = closest(dominoes, "R")
        left = closest(dominoes[::-1], "L")[::-1]
        
        ans = [None] * N
        
        for i in range(N):      
            left[i] = min(INF, left[i])
            right[i]  = min(INF, right[i])
            
            if left[i] < right[i]:
                ans[i] = "L"
            elif left[i] > right[i]:
                ans[i] = "R"
            else:
                ans[i] = "."
        
        return "".join(ans)
            
