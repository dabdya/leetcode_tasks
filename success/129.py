# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.sum_ = 0
        self.traverse(root, f"{root.val}")
        return self.sum_
        
    
    def traverse(self, root, num):
        
        if not root.left and not root.right:
            self.sum_ += int(num)
        
        if root.right:
            self.traverse(root.right, num + str(root.right.val))
        
        if root.left:
            self.traverse(root.left, num + str(root.left.val))
        
        