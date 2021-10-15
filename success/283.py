class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        zeros = 0
        
        for i in range(n):
            if nums[i] == 0:
                zeros += 1
                
        ptr = 0
        for i in range(n):
            if nums[i] == 0:
                continue
            
            nums[ptr] = nums[i]
            ptr += 1
        
        for i in range(zeros):
            nums[n-i-1] = 0
