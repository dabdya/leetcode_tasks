from collections import Counter


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mulset1 = Counter(nums1)
        mulset2 = Counter(nums2)
        
        res = []
        for item in mulset1:
            if item in mulset2:
                """Работает не за квадрат, так как мультисет содержит не больше чем n элементов"""
                n = min(mulset1[item], mulset2[item])
                for _ in range(n):
                    res.append(item)
                    
        return res