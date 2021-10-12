# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        
        """Задача на бинарный поиск"""
        
        lp = 1; rp = n
        
        while lp != rp:
            m = (lp + rp) // 2
            g = guess(m)
            
            if g == 0:
                return m
            
            if g == -1:
                rp = m-1
            else:
                lp = m+1
        
        return lp
            
            