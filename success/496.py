class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums1)
        m = len(nums2)
        
        greaters = dict()
        stack = []
        
        for i in range(m):
            while stack and nums2[i] > stack[-1]:
                greaters[stack.pop()] = nums2[i]
            stack.append(nums2[i])
        
        while stack:
            greaters[stack.pop()] = -1
            
        return [greaters[num] for num in nums1]
            