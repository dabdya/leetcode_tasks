class Solution:
    def reverseWords(self, s: str) -> str:
        
        return " ".join([word.strip() for word in s.split()[::-1]])