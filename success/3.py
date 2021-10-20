from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        bound = 0
        freq = defaultdict(int)
        
        res = 0
        for i in range(n):
            freq[s[i]] += 1
            if freq[s[i]] > 1:
                
                while s[bound] != s[i]:
                    freq[s[bound]] -= 1
                    bound += 1
                
                freq[s[bound]] -= 1
                bound += 1
            
            res = max(res, i - bound + 1)
        
        """time: O(n), space: O(n)"""
        return res