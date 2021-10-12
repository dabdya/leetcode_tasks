class Solution:
    def exist(self, board, word: str) -> bool:
        
        n = len(board)
        m = len(board[0])
        visited = set()
        
        def dfs(i, j, k):
            visited.add((i,j))
            if board[i][j] != word[len(word)-k]:
                visited.remove((i,j))
                return False
            elif k == 1:
                return True

            if i-1 >= 0 and k > 1 and (i-1,j) not in visited and dfs(i-1,j,k-1):
                return True
            
            if i+1 < n and k > 1 and (i+1,j) not in visited and dfs(i+1,j,k-1):
                return True
            
            if j-1 >= 0 and k> 1 and (i,j-1) not in visited and dfs(i,j-1,k-1):
                return True
            
            if j+1 < m and k > 1 and (i,j+1) not in visited and dfs(i,j+1,k-1):
                return True
            
            visited.remove((i,j))
            return False
        
        
        for i in range(n):
            for j in range(m):
                
                if board[i][j] == word[0]:
                    visited.clear()
                    if dfs(i, j, len(word)):
                        return True
                    
        return False