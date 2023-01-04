class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        res = 0
        count = {}
        tasks.sort()
        for i in tasks:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        for i in count:
            while count[i]:
                if count[i] == 1:
                    return -1
                if count[i] % 3 == 0:
                    count[i] -= 3
                else:
                    count[i] -= 2
                res += 1
        return res
