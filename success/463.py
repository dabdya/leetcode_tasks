class Solution:
    def islandPerimeter(self, grid) -> int:
        n = len(grid)
        m = len(grid[0])
        
        result = 0
        
        def process(i, j):
            res = 0
            
            if i-1 >= 0:
                if not grid[i-1][j]: res += 1
            else:
                res += 1
                    
            if i+1 < n:
                if not grid[i+1][j]: res += 1
            else:
                res += 1                    
                
            if j-1 >= 0:
                if not grid[i][j-1]: res += 1
            else:
                res += 1
                
            if j+1 < m:
                if not grid[i][j+1]: res += 1
            else:
                res += 1
            return res
            
        
        for i in range(n):
            for j in range(m):
                
                if not grid[i][j]: 
                    continue
                result += process(i,j)
        
        return result