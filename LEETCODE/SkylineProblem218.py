# Use a priority queue q to store all y-axis heights in descending order and use maps beg and 
# end to store y-axis heights per x-axis value for each building's beginning x1 and ending x2 correspondingly. 
# Then perform a linear scan upon the sorted x-axis values seen, and append the current x-axis and height onto the answer ans whenever the current height has changed, ie. when the last height is not equal to the current height.
# Note: we use a counter cnt to store the frequency of each y-axis value in the priority queue q, this allows for a sorted multiset priority queue q which is necessary when the buildings overlap at the same height (see test case 35 of 40 as an example below)
# Test case 35 of 40: A = [[3,7,8],[3,8,7],[3,9,6],[3,10,5],[3,11,4],[3,12,3],[3,13,2],[3,14,1]]


from sortedcontainers import SortedSet
VI = List[int]
VVI = List[VI]
class Solution:
    def getSkyline(self, A: VVI) -> VVI:
        ans = []
        q, cnt = SortedSet([], neg), Counter()
        beg, end, seen = defaultdict(list), defaultdict(list), set()
        for x1, x2, y in A:
            beg[x1].append(y); seen.add(x1)
            end[x2].append(y); seen.add(x2)
        last, height = 0, 0
        for x in sorted(seen):
            last = height
            for y in end[x]:
                cnt[y] -= 1
                if not cnt[y]: q.remove(y)
            for y in beg[x]:
                q.add(y); cnt[y] += 1
            height = q[0] if len(q) else 0
            if last != height:
                ans.append([x, height])
        return ans
