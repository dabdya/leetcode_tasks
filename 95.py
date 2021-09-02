from itertools import permutations


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def add(self, val):
        if self.val < val:
            if not self.right:
                self.right = TreeNode(val)
            else:
                self.right.add(val)
        
        if self.val > val:
            if not self.left:
                self.left = TreeNode(val)
            else:
                self.left.add(val)
    
    def __eq__(self, other):
        return self.__hash__() == hash(other)
    
    def __hash__(self):
        return hash(self.to_tuple())
    
    def to_tuple(self):
        self.__list = [self.val]
        if self.left:
            self.__list += self.left.to_tuple()
        
        if self.right:
            self.__list += self.right.to_tuple()
            
        return tuple(self.__list)
        
        
        
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        trees = set()
        for verticesOrder in permutations(range(1, n+1)):
            tree = self.generateTree(verticesOrder)
            trees.add(tree)
        return list(trees)
    
    def generateTree(self, verticesOrder):
        n = len(verticesOrder)
        root = TreeNode(verticesOrder[0])
        for i in range(1, n):
            root.add(verticesOrder[i])
        return root