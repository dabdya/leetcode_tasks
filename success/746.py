class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0]*(n+1)
        for i in range(n):
            dp[i] = cost[i]
        
        for i in range(2,n+1):
            dp[i] += min(dp[i-2], dp[i-1])
        
        return dp[n]
    
    """Обычная задача про кузнечика, только нужно было добавить последнюю ступеньку с ценой 0"""