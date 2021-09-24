from collections import defaultdict


class Solution:
    def carPooling(self, trips, capacity: int) -> bool:
        start = defaultdict(int)
        end = defaultdict(int)
        
        for trip in trips:
            c, s, e = trip
            start[s] += c
            end[e] += c
        
        cur_capacity = 0
        for x in range(1000):
            if x in start:
                cur_capacity += start[x]
            if x in end:
                cur_capacity -= end[x]
            
            if cur_capacity > capacity:
                return False
        
        return True
    
    """time: O(n), space: O(n), n = len(trips)"""