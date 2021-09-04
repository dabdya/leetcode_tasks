class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        n = len(nums)
        part_sums = [0]*n
        part_sums[0] = nums[0]
        for i in range(1,n):
            part_sums[i] = part_sums[i-1] + nums[i]
        
        for i in range(n):
            right_side = 0 if i == n-1 else part_sums[-1] - part_sums[i]
            left_side = 0 if i == 0 else part_sums[i-1]
            if left_side == right_side:
                return i
        return -1