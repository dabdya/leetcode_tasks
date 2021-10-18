# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:

        """"""        
        def find_val(val):
            
            stack = [(root, 0, TreeNode())]

            while stack:
                node, depth, parent = stack.pop()
                if node.val == val:
                    return depth, parent.val
                
                if node.left:
                    stack.append((node.left, depth+1, node))
                if node.right:
                    stack.append((node.right, depth+1, node))
        
        dx, px = find_val(x)
        dy, py = find_val(y)
        
        """time: O(n), space: O(n)"""
        
        return dx == dy and px != py
                    