class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        
        res = 1
        count = 0
        last = None
        
        for i in range(1,n):
            if not last:
                if arr[i] > arr[i-1]:
                    last = 'gr'
                    count += 2
                elif arr[i] < arr[i-1]:
                    last = 'lt'
                    count += 2
                continue
    
            if arr[i] > arr[i-1]:
                if last == 'gr':
                    res = max(res,count)
                    count = 2
                else:
                    last = 'gr'
                    count += 1
                    
            elif arr[i] < arr[i-1]:
                if last == 'lt':
                    res = max(res,count)
                    count = 2
                else:
                    last = 'lt'
                    count += 1
            
            else:
                res = max(res,count)
                count = 0
                last = None
                
        return max(res,count)