from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        
        res = []
        for char, freq in cnt.most_common():
            res.append(char*freq)
        
        return "".join(res)