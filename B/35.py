class Solution:
    def searchInsert(self, nums, target: int) -> int:
        
        n = len(nums)
        lp = 0
        rp = n-1
        
        if rp == lp:
            return 0 if nums[lp] >= target else 1
        
        while rp - lp != 1:
            
            m = (lp + rp) // 2
            if nums[m] == target:
                return m
            
            if nums[m] < target:
                lp = m
            else:
                rp = m
        
        if nums[lp] == target: return lp
        if nums[rp] == target: return rp
        
        if target < nums[lp]:
            return max(lp-1, 0)
        if target > nums[rp]:
            return min(rp+1, n)
            
        return rp
        