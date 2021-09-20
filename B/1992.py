class Solution:
    def findFarmland(self, land):
        n = len(land)
        m = len(land[0])
        
        self.g = dict()
        for i in range(n):
            for j in range(m):
                if not land[i][j]:
                    continue
                cell = i,j   
                if cell not in self.g:
                    self.g[cell] = []
                
                # left neighbour
                if i > 0 and land[i-1][j]:
                    self.g[cell].append((i-1,j))
                
                # top neighbour
                if j > 0 and land[i][j-1]:
                    self.g[cell].append((i,j-1))
                    
                # bottom neighbour
                if j < m-1 and land[i][j+1]:
                    self.g[cell].append((i,j+1))
                    
                # right neighbour
                if i < n-1 and land[i+1][j]:
                    self.g[cell].append((i+1,j))
        
        res = []
        self.visited = set()
        for u in self.g:
            if u not in self.visited:
                left_top, right_bottom = self.dfs(u,u,u)
                res.append([left_top[0], left_top[1],
                           right_bottom[0], right_bottom[1]])     
        return res

        """time: O(n*m)"""
    
    def update_left(self, left_top, u):
        """Support left_top corner"""
        if u[0] <= left_top[0] and u[1] <= left_top[1]:
            left_top = u
        return left_top

    def update_right(self, right_bottom, u):
        """Support right_bottom corner"""
        if u[0] >= right_bottom[0] and u[1] >= right_bottom[1]:
            right_bottom = u
        return right_bottom
                    
    def dfs(self, u, left_top, right_bottom):
        self.visited.add(u)
        left_top = self.update_left(left_top, u)
        right_bottom = self.update_right(right_bottom, u)
        
        for v in self.g[u]: # expected empty list if not neighbours
            if v not in self.visited:
                res_left, res_right = self.dfs(v, left_top, right_bottom)
                left_top = self.update_left(left_top, res_left)
                right_bottom = self.update_right(right_bottom, res_right)
        
        return left_top, right_bottom           