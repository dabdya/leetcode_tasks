class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        n = len(nums)
        m = len(l)
        
        res = []
        for i in range(m):
            d = -1
            subarr = sorted(nums[l[i]:r[i]+1])
            for j in range(1, len(subarr)):
                if d == -1:
                    d = subarr[j] - subarr[j-1]
                else:
                    if d != subarr[j] - subarr[j-1]:
                        res.append(False)
                        break
            else:
                res.append(True)
        
        return res
    
        """time: O(mnlogn), space:(m+n)"""
        """Подумать как улучшить до O(nm)"""