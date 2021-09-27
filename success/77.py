class Solution:
    def __init__(self):
        self.res = []
        self.cur = []
        
    def dfs(self, start, n, k):
        k -= 1
        
        for num in range(start, n+1):
            self.cur.append(num)
            if k != 0:
                self.dfs(num+1, n, k)
            else:
                self.res.append(self.cur[:])
            self.cur.pop()
        
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.dfs(1, n, k)
        return self.res