# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum_ = 0
        
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:

        if not root:
            return 0
        
        if root.left:
            if not root.left.left and not root.left.right:
                self.sum_ += root.left.val
            self.sumOfLeftLeaves(root.left)
        
        if root.right:
            self.sumOfLeftLeaves(root.right)
            
        return self.sum_