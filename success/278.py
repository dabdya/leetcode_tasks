# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        lp = 1
        rp = n
        
        while lp != rp:
            m = (lp + rp) // 2
            is_bad = isBadVersion(m)
            if is_bad:
                rp = m
            else:
                lp = m + 1
            
        return rp