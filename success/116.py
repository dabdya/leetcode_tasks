"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

from queue import Queue

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
#         """Bound cases"""
#         if not root or (not root.left and not root.right):
#             return root
        
#         queue = Queue()
#         queue.put(root.left)
#         queue.put(root.right)
        
#         while queue.qsize() != 0:
            
#             n = queue.qsize()
#             outer = None
            
#             for i in range(n//2):
#                 left = queue.get()
#                 right = queue.get()
#                 left.next = right
                
#                 if outer:
#                     outer.next = left
#                 outer = right
                
#                 if left.left and left.right:
#                     queue.put(left.left)
#                     queue.put(left.right)
                    
#                 if right.left and right.right:
#                     queue.put(right.left)
#                     queue.put(right.right)
        
#         return root

        """Вариант выше не самый оптимальный, можно сделать рекурсией без дополнительной памяти"""
    
        """Bound cases"""
        if not root or (not root.left and not root.right):
            return root
        
        def traverse(parent, h):
            """Условие остановки рекурсии"""
            if not parent.left and not parent.right:
                return 
            
            node = parent
            
            for i in range(h):
                node.left.next = node.right
                if node.next:
                    node.right.next = node.next.left
                    node = node.next
            
            traverse(parent.left, h*2)
            
        traverse(root, 1)
        return root
    
        """Время улучшилось почти в два раза, память совсем немного..."""
            