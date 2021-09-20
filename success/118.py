class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        
        for _ in range(numRows-1):
            n = len(res[-1])
            level = [1]
            for i in range(1, n):
                nxt = res[-1][i] + res[-1][i-1]
                level.append(nxt)
            level.append(1)
            res.append(level)
        return res
    
    """Временная сложность O(n^2)
       Пространственная сложность O(n)
       Можно также отметить, что каждый уровень в треугольнике Паскаля представляет
       коэффициенты в разложение n-ой степени многочлена."""