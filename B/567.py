from string import ascii_lowercase


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        """
        Amazing illustrations 
        https://stackoverflow.com/questions/8269916/what-is-sliding-window-algorithm-examples
        """
        
        if len(s1) > len(s2): return False
        
        n = len(ascii_lowercase)
        target = [0] * n
        
        for char in s1:
            target[ord(char)%n] += 1
        
        ws = len(s1) # window size
        
        current = [0] * n
        for i in range(ws):
            current[ord(s2[i])%n] += 1
        
        for i in range(len(s2)-ws+1):
            if i-1 >= 0:
                current[ord(s2[i-1])%n] -= 1
                current[ord(s2[i+ws-1])%n] += 1
                
            if current == target:
                return True
            
        return False
        