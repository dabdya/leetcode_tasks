# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        stack = []
        while head.next:
            stack.append(head.val)
            head = head.next
            
        res = ListNode(head.val)
        
        current = res
        while stack:
            nxt = ListNode(stack.pop())
            current.next = nxt
            current = nxt
        return res
            