# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        """Bound cases"""
        if not head: return
        if not head.next: return head
        
        prev = ListNode(val=head.val)
        head = head.next
        
        while head.next:
            nxt = head.next
            head.next = prev
            prev = head
            head = nxt
            
        head.next = prev
        return head
            
            