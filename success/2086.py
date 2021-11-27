class Solution:
    def minimumBuckets(self, street: str) -> int:
        
        if len(street) == 1:
            if street[0] == 'H': return -1
            return 0
        
        res = 0
        n = len(street)
        arr = list(street)
        
        for i in range(n):
            
            if arr[i] != 'H' or i > 0 and arr[i - 1] == 'B':
                continue
            
            if 0 < i < n - 1 and arr[i - 1] == 'H' and arr[i + 1] == 'H':
                return -1
            
            if i > 0 and arr[i - 1] == 'H':
                if i == n - 1: return - 1
                arr[i + 1] = 'B'
            
            elif i < n - 1 and arr[i + 1] == 'H':
                if i == 0: return -1
                arr[i - 1] = 'B'

            elif i < n - 1:
                arr[i + 1] = 'B'
            elif i == n - 1:
                arr[i - 1] = 'B'
            else:
                continue
                
            res += 1
        
        return res