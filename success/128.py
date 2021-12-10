class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        longest = 0
        numset = set(nums)
        
        for num in numset:
            if num - 1 not in numset:
                curnum = num
                curlongest = 1
                
                while curnum + 1 in numset:
                    curnum += 1
                    curlongest += 1
                
                longest = max(longest, curlongest)
        
        return longest