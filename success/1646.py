class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0:
            return 0
        dp = [0]*(n+1)
        dp[0] = 0
        dp[1] = 1
        
        result = 1
        for i in range(1, n//2+1):
            if 2*i < n+1:
                dp[2*i] = dp[i]
                result = max(result, dp[2*i])
            if 2*i+1 < n+1:
                dp[2*i+1] = dp[i] + dp[i+1]
                result = max(result, dp[2*i+1])
        
        return result