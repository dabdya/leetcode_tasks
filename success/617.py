# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        
        """Bounds cases"""
        if not root1: return root2
        if not root2: return root1
        
        def traverse(node1, node2):
            """Будем мерджить в левое дерево"""
            node1.val += node2.val
            
            if node1.left and node2.left:
                traverse(node1.left, node2.left)
            if not node1.left and node2.left:
                node1.left = node2.left
            
            if node1.right and node2.right:
                traverse(node1.right, node2.right)
            if not node1.right and node2.right:
                node1.right = node2.right
            
        traverse(root1, root2)
        return root1