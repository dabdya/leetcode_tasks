class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        n = len(nums)
        lp = 0
        rp = n - 1
        
        while lp != rp:
            
            s = nums[lp] + nums[rp]
            if s == target:
                return [lp+1, rp+1]
            
            if s < target:
                lp += 1
            else:
                rp -= 1