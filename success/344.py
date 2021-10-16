class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # s.reverse()
        lp = 0
        rp = len(s) - 1
        
        while lp != rp:
            
            s[lp], s[rp] = s[rp], s[lp]
        
            lp += 1
            rp -= 1
            if rp < lp:
                break