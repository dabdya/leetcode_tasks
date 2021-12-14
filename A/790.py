from functools import lru_cache

class Solution:
    def numTilings(self, n: int) -> int:
        self.mod = 10**9 + 7
        # https://leetcode.com/problems/domino-and-tromino-tiling/discuss/1620975/C%2B%2BPython-Simple-Solution-w-Images-and-Explanation-or-Optimization-from-Brute-Force-to-DP
        return self.search(0, n, False)
    
    @lru_cache
    def search(self, i, n, space):
        
        if i > n: return 0
        if i == n: return 0 if space else 1
        
        if space:
            return (self.search(i+1, n, False) + self.search(i+1, n, True)) % self.mod
        return (
            self.search(i+1, n, False) + 
            self.search(i+2, n, False) + 
            2 * self.search(i+2, n, True)) % self.mod