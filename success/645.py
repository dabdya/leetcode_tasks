class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        s = set()
        
        result = []
        for i in range(n):
            if nums[i] not in s:
                s.add(nums[i])
            else:
                result.append(nums[i])
        
        for i in range(1, n+1):
            if i not in s:
                result.append(i)
                break
        
        return result