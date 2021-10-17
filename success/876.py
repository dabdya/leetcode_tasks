# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        count = 1
        node = head
        while node.next:
            node = node.next
            count += 1
        
        res = head
        n = count // 2
        while n > 0:
            res = res.next
            n -= 1
        
        return res