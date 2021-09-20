from collections import Counter


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        
        """Важно понять какие здесь подзадачи:
            f([1..n]) = max(f([1..n-1]), f([1..n-2]) + freq(n-1)*(n-1))
            То есть, каждый раз можно либо включать элемент, либо нет.
            Если не включать, смотрим f([1..n-1]). Если включаем:
            смотрим последнее не конфликтующее f([1..n-2]) если n-2 в словаре,
            прибавляя к нему частоту, умноженную на само текущее число.
            Если же n-2 не словаре, то конфликта нет, а значит ответ
            это просто текущее число на чатоту плюс f([1..n-1]) (
            подзадача через один назад, для нее рассуждения такие же)"""
        
        freq = Counter(nums)
        n = len(freq)
        dp = [0]*(n+1)
        for i,num in enumerate(sorted(freq.keys())):
            if i == 0:
                dp[i+1] = freq[num]*num
                continue
            
            if num-1 in freq:
                dp[i+1] = max(dp[i], dp[i-1] + freq[num]*num)
            else:
                dp[i+1] = dp[i] + freq[num]*num
        
        return dp[n]