from string import ascii_letters


class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        n = len(s)
        l = 0
        r = n-1
        
        res = [""]*n
        #alph = set(ascii_letters)
        while l < r+1:
            lcond = s[l] in ascii_letters
            rcond = s[r] in ascii_letters
            if lcond and rcond:
                res[l], res[r] = s[r], s[l]
                l += 1
                r -= 1
            elif lcond and not rcond:
                res[r] = s[r]
                r -= 1
            elif rcond and not lcond:
                res[l] = s[l]
                l +=1
            else:
                res[l], res[r] = s[l], s[r]
                l += 1
                r -= 1
        
        return "".join(res)