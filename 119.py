class Solution:    
    def getRow(self, n: int) -> List[int]:
        
        """Иногда ДП заключается в том, что в начале нужно что-то предпосчитать,
           чтобы потом это использовать. Сейчас нужно посчитать факториал."""
        
        dp = [0]*(n+1)
        dp[0] = 1
        for i in range(1,n+1):
            dp[i] = dp[i-1]*i
        
        level = []
        for k in range(n//2 + 1):
            c = dp[n]//(dp[k]*dp[n-k])
            level.append(c)
            
        start = n//2
        if n % 2 == 0:
            start -= 1
            
        for i in range(start, -1, -1):
            level.append(level[i])
            
        return level
    
    """Не мой способ, но тоже прикольный.
        Это если вдруг не будет питона, чтобы посчитать факториал"""
    
#         dp = [0]*(n+1)
#         dp[0] = 1

#         for i in range(1,n+1):
#             for j in range(i, 0, -1):
#                 dp[j] += dp[j-1]

#         return dp
        