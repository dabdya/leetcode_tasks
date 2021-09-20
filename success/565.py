class Solution:
	def dfs(self, u, h):
		self.visited.add(u)
		for v in self.g[u]:
			if v not in self.visited:
				return self.dfs(v, h+1)
		return h

    def arrayNesting(self, nums):
    	n = len(nums)
    	self.g = [[] for _ in range(n)]
    	for u in range(n):
    		v = nums[u]
    		self.g[u].append(v)
    		self.g[v].append(u)

    	count = 0
    	self.visited = set()	
    	for i in range(n):
    		if i not in self.visited:
    			count = max(count, self.dfs(i, 1))

    	return count