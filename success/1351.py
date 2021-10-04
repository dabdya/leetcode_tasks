class Solution:
    def countNegatives(self, grid) -> int:
        
        result = 0
        for row in grid:
            for cell in row:
                if cell < 0:
                    result += 1
                    
        return result