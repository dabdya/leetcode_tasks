from collections import Counter

class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        cnt1 = Counter(words1)
        cnt2 = Counter(words2)
        
        return len([k for k,v in cnt1.items() if v == 1 and k in cnt2 and cnt2[k] == 1])