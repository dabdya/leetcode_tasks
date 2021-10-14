class Solution:
    def rotate(self, nums, k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        n = len(nums)
        k %= n
        
        def reverse(start, end):
            while start < end:
                
                temp = nums[start]
                nums[start] = nums[end]
                nums[end] = temp
                
                start += 1
                end -= 1
                
        reverse(0, n-1)
        reverse(0, k-1)
        reverse(k, n-1)

        
#         n = len(nums)
        
#         pos = dict()
#         for i in range(n):
#             pos[(i + k) % n] = nums[i]
        
#         for p in pos:
#             nums[p] = pos[p]