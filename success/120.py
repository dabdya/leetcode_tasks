class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        n = len(triangle)
        dp = [[0] * len(triangle[i]) for i in range(n)]
        
        """Base"""
        dp[0][0] = triangle[0][0]
        
        """dp[[n][k] = минимальный путь в клетку k на уровне n"""
        
        for i in range(1,n):
            m = len(triangle[i])
            for j in range(m):
                
                
                """Крайние особые случае, на них влияет только один элемент"""
                if j == 0:
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                
                elif j == m-1:
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                
                else:
                    """Важно заметить, что на каждый текущий элемент влияют
                       только два предыдущих элемента"""
                    dp[i][j] = min(dp[i-1][j-1] + triangle[i][j],
                                   dp[i-1][j] + triangle[i][j])
        
        """Ответ лежит на последнем уровне, он минимальный"""
        return min(dp[n-1])
    
        """space <= O(n^2)
           time <= O(n^2))
           Здесь перед квадратом хорошая константа, но в целом ассимптотически квадрат
           При заданных в условии n алгоритм должен отработать адекватно"""
        