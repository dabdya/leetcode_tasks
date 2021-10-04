from functools import lru_cache

class Solution:
    def PredictTheWinner(self, nums):
        
        @lru_cache
        def dfs(arr, step):
            n = len(arr)
            
            if n == 1:
                return arr[0] if step == 'PL1' else -arr[0]
            
            if step == 'PL1':
                return max(
                    arr[0] + dfs(arr[1:], 'PL2'), 
                    arr[n-1] + dfs(arr[:n-1], 'PL2'))
            else:
                return min(
                    -arr[0] + dfs(arr[1:], 'PL1'),
                    -arr[n-1] + dfs(arr[:n-1], 'PL1'))
        
        return dfs(tuple(nums), 'PL1') >= 0