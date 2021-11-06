class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # return self.bit_manip_approach(nums)
        
        self.powerset = [[],]
        self.recursive_approach(0, [], nums)
        return self.powerset
        
    def bit_manip_approach(self, nums):
        powerset = []
        n = len(nums)
        
        for i in range(2**n):
            subset = []
            ibin = bin(i)[2:]
            for j, bit in enumerate(ibin):
                if bit == '1':
                    subset.append(nums[len(ibin)-j-1])
            powerset.append(subset)
        return powerset
    
    def recursive_approach(self, s, templist, nums):
        if (s == len(nums)): return
        
        for i in range(s, len(nums)):
            templist.append(nums[i])
            self.powerset.append(templist[:])
            self.recursive_approach(i+1, templist, nums)
            templist.pop()
            
    # time in both cases: O(n * 2^n)