class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        # visited = set()
        
        def dfs(v):
            """Должен вернуть размер компоненты связности"""
            # visited.add(v)
            
            i,j = v
            grid[i][j] *= -1
            count = 0
            if i-1 >=0 and grid[i-1][j] == 1:
                count += dfs((i-1,j))
                
            if i+1 < n and grid[i+1][j] == 1:
                count += dfs((i+1,j))
            
            if j-1 >= 0 and grid[i][j-1] == 1:
                count += dfs((i,j-1))
            
            if j+1 < m and grid[i][j+1] == 1:
                count += dfs((i,j+1))
            
            return count + 1
        
        res = 0
        for i in range(n):
            for j in range(m):
                
                if grid[i][j] == 1:
                    res = max(res, dfs((i,j)))
                    
        return res
    
    """Временная сложность O(m*n + m+n)
       Пространственная сложность O(m*n)"""
    
    """Оптимизация без visited достигает довольно легко"""