# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        return self.traverse(root, subRoot, False)
    
    def traverse(self, root, subRoot, process):
        if not root and not subRoot:
            return True
        
        if not root or not subRoot:
            return False
        
        if root.val == subRoot.val:
            left_same = self.traverse(root.left, subRoot.left, True)
            right_same = self.traverse(root.right, subRoot.right, True)
            if left_same and right_same:
                return True
            if (not left_same or not right_same) and process:
                return False
        elif process:
            return False
            
        if root.right:
            if self.traverse(root.right, subRoot, False):
                return True
        
        if root.left:
            if self.traverse(root.left, subRoot, False):
                return True
        
        return False