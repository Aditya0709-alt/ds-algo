from collections import defaultdict
from math import gcd 
from typing import DefaultDict, List, Tuple



class Solution:

    intPair = Tuple[int, int]

    def normalisedSlope(self, a: intPair, b: intPair) -> intPair:
        run = b[0] - a[0]

        if run == 0:
            return (1,0)
        
        if run < 0:
            a, b = b, a
            run = b[0] - a[0]
        
        rise = b[1] - a[1]

        gcd_ = gcd(abs(rise), run)

        return (rise // gcd_, run // gcd_)


    def maxPoints(self, points: List[List[int]]) -> int:
        
        if len(points) < 3:
            return len(points)
        
        maxVal = 0

        for i in range(0, len(points) - 1):
            a = tuple(points[i])

            slopeCounts: DefaultDict[intPair, int] = defaultdict(lambda: 1)

            for j in range(i+1, len(points)):
                b = tuple(points[j])

                slopeCounts[self.normalisedSlope(a, b)] += 1 

            maxVal = max(maxVal, max(slopeCounts.values()))

        return maxVal 
