class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            if i+1 != nums[i]:
                return [nums[i], i+1]