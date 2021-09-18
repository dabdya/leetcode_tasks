class Solution:
    def __init__(self):
        self.adj_list = {
            1: [2,3,5,6,11],
            2: [1,4,7,9,12],
            3: [1,4,7,8],
            4: [2,3,8,11],
            5: [1,7,9,10],
            6: [1,7,8,10,11],
            7: [2,3,5,6,12],
            8: [3,4,6,12],
            9: [2,5,10,11],
            10: [5,6,9,12],
            11: [1,4,6,9,12],
            12: [2,7,8,10,11]
        }
        
        """Для каждой доминошки храниться список возможных продолжений.
           Нумерация сначала по горизонтали, потом по вертикали."""
        
    def numOfWays(self, n: int) -> int:
        """Нужно поддерживать количество доминошек каждого вида на последнем уровне,
        т.е. на том уровне, который продолжается."""
        freq = {i : 1 for i in range(1,13)} # для n = 1
        
        mod = 10**9 + 7
        while n != 1:
            
            curr = {i : 0 for i in range(1,13)}
            for dnum in self.adj_list:
                for nxt in self.adj_list[dnum]:
                    curr[nxt] = (curr[nxt] + freq[dnum]) % mod
            
            freq = curr
            n -= 1
            
        return sum(freq.values()) % mod
        """time: O(60n) = O(n), space: O(1)"""