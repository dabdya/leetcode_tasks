from collections import Counter

class HashTuple:
    def __init__(self, tuple_):
        self.tuple_ = tuple_
        self.n = len(self.tuple_)
        
    def __hash__(self):
        return hash(tuple(sorted(self.tuple_)))
    
    def __eq__(self, other):
        return Counter(self.tuple_) == Counter(other.tuple_)
        
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        powerset = set()
        n = len(nums)
        
        for i in range(2**n):
            subset = []
            ibin = bin(i)[2:]
            for j, bit in enumerate(ibin):
                if bit == '1':
                    subset.append(nums[len(ibin)-j-1])
            powerset.add(HashTuple(subset))
        return [set_.tuple_ for set_ in powerset]