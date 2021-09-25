class Solution:
    def leastBricks(self, wall) -> int:
        n = len(wall)
        edges = dict()
        
        """Идея: пройтись по всем разрезам и найти в какой точке их больше всего.
           Поскольку разрезы не считаются, это будет означать, что в этой точке
           меньше всего пересечений кирпичей не по разрезам, что и является ответом."""
        
        for row in wall:
            m = len(row)
            acc = 0
            for i in range(m):
                if i == m-1 and m > 1:
                    break
                acc += row[i]
                if acc not in edges:
                    edges[acc] = n
                edges[acc] -= 1
                
        res = min(edges.values())
        """Обработка крайнего случая, когда длины всех стен 1"""
        same_len = all(map(lambda x: len(x) == 1, wall))
        return res if res >= 0 and not same_len else n
    """time: O(n^2), space: O(n)"""