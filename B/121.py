class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """На каждой итерации надо поддерживать минимальный элемент, который
        будет оптимальным днем покупки, а на каждой последующей считать профит,
        и обновлять его, если он стал больше."""
        
        n = len(prices)
        buy = prices[0]
        max_profit = float('-inf')
        for i in range(1,n):
            profit = prices[i]-buy
            if profit > max_profit:
                max_profit = profit
            if profit < 0:
                buy = prices[i]
        
        return max_profit if max_profit > 0 else 0