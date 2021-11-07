class Solution:
    def __init__(self):
        self.permutations = []
        self.permutation = []
        
    def permute(self, nums: List[int]) -> List[List[int]]:
        visited = [False for _ in range(len(nums))]
        self.recursive_approach(nums, visited)
        return self.permutations
        
    def recursive_approach(self, nums, visited):

        if len(self.permutation) == len(nums):
            self.permutations.append(self.permutation[:])
            return
        
        for i in range(len(nums)):
            if not visited[i]:
                
                self.permutation.append(nums[i])
                visited[i] = True
                
                self.recursive_approach(nums, visited)
                
                self.permutation.pop()
                visited[i] = False