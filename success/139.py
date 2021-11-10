from functools import lru_cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        return self.search(s, 0, tuple(wordDict))
        
    @lru_cache
    def search(self, s, ptr, words) -> bool:
        words = set(words)
        tmp_str = s[ptr]
        for i in range(ptr + 1, len(s)):
            if tmp_str in words and self.search(s, i, tuple(words)):
                return True
            tmp_str += s[i]
        
        return tmp_str in words