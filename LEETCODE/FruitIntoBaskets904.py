# Imagine you are standing near the tree i. You have to choose between two options:

# Add fruits[i] to one of your busket which has the same type of fruits
# Empty one of your busket and put there fruits[i]
# Think about the information you need to know about the trees [0, i - 1] in order to perform one of those possible actions. You need to know the position of the tree where you picked your first fruit in the busket and the position of the tree where you started picking your the fruits of the second type.

# Complexity
# Time complexity:
# O(n) since we go through array only once.

# Space complexity:
# O(1) since we don't use any externally created arrays, only a few additional integer variables.

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        i, j = 0, 0
        n = len(fruits)
        while j < n and fruits[i] == fruits[j]:
            j += 1
        if j == n:
            return n

        l, r = i, j + 1
        answ = 0
        while r < n:
            if fruits[r] != fruits[j]:
                if fruits[r] == fruits[i]:
                    i = j
                    j = r
                else:
                    answ = max(answ, r - l)
                    i = j
                    l = j
                    j = r
            r += 1
        answ = max(answ, r - l)
        return answ
