class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        
        if n == 3:
            return 2
        
        dp = [0]*n
        dp[0] = 1
        dp[1] = 2
        dp[2] = 3
        
        """Особые случаи это n=3 и n=2, когда f(3)=2, f(2)=1, поскольку нужно как
           минимум два множителя. А в разложении других чисел f(3)=3, f(2)=2."""
        
        for i in range(3,n):
            for j in range(1, (i+1)//2 + 1):
                dp[i] = max(dp[i], dp[j-1]*dp[i-j])
                
        return dp[n-1]