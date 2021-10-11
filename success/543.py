# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        """У КАЖДОЙ вершины есть глубина левого и правого поддерева,
           родителю нужно отдавать максимум из них, и постоянно
           обновлять глобальный результат"""
        
        res = 0
        def dfs(vertice):
            nonlocal res
            left = dfs(vertice.left) if vertice.left else 0
            right = dfs(vertice.right) if vertice.right else 0
            res = max(res, left+right)
            return max(left, right)+1
        
        dfs(root)
        return res