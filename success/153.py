class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        n = len(nums)
        
        "Bound cases"
        if n == 1: return nums[0]
        if nums[0] < nums[-1]: return nums[0]
        
        
        lp = -1; rp = n-1
        
        """Если медиана больше чем правый элемент, то двигаем левый указатель
           Если медиана меньше чем правый элемент, то двигаем правый указатель 
           и обновляем результат, но поиск продолжается, т.к. могут быть элементы еще меньше"""
        
        res = float('inf')
        
        while rp - lp > 1:
            
            m = (rp + lp) // 2
            
            if nums[m] < nums[rp]:
                res = min(res, nums[m])
                rp = m
            else:
                lp = m
        
        return min(res, nums[lp], nums[rp])