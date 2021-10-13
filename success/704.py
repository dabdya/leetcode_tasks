class Solution:
    def search(self, nums, target: int) -> int:
        
        n = len(nums)
        lp = 0
        rp = n-1
        
        while lp != rp:
            
            m = (lp + rp) // 2
            
            if nums[m] == target:
                return m
            
            if nums[m] < target:
                lp = m + 1
            else:
                rp = m - 1
            
            if rp < 0 or lp > n-1:
                return -1
        
        return lp if nums[lp] == target else -1