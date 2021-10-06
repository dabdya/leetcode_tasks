class Solution:
    def maxScoreSightseeingPair(self, values):
        
        n = len(values)
        
        result = float('-inf')
        curmax = values[0]
        
        """Не нужно строить рекурсию, она здесь никак не кэшируется, и поэтому
           сложность будет O(2^n). Вместо этого надо вести учет предыдущего лучшего
           values[i]+i, и на каждом шаге прибавлять values[j]-j, обновляя результат."""
        
        for i in range(1,n):
            
            result = max(result, curmax+values[i]-i)
            
            if curmax < values[i]+i:
                curmax = values[i]+i
        
        return result