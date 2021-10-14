class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        for i in range(n):
            nums[i] = nums[i]**2
            
        lp = 0; rp = n-1
        
        res = []
        while lp != rp:
            if nums[lp] < nums[rp]:
                res.append(nums[rp])
                rp -= 1
            else:
                res.append(nums[lp])
                lp += 1
        
        res.append(nums[lp])
        res.reverse()
        return res