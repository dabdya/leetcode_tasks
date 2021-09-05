class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        sp = 0 # указатель по строке s
        tp = 0 # указатель по строке t
        
        while sp < len(s) and tp < len(t):
            if s[sp] == t[tp]:
                sp += 1
            tp += 1
        
        return sp == len(s)